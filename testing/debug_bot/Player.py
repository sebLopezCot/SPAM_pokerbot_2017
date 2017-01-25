import argparse
import socket
import sys

"""
Simple example pokerbot, written in python.

This is an example of a bare bones pokerbot. It only sets up the socket
necessary to connect with the engine and then always returns the same action.
It is meant as an example of how a pokerbot should communicate with the engine.
"""
class Player:
    def run(self, input_socket):
        # Get a file-object for reading packets from the socket.
        # Using this ensures that you get exactly one packet per read.
        f_in = input_socket.makefile()
        hand = []
        start_bank_size = 0
        m_name = ''
        just_discarded = False
        while True:
            # Block until the engine sends us a packet.
            data = f_in.readline().strip()
            # If data is None, connection has closed.
            if not data:
                print "Gameover, engine disconnected."
                break

            # Here is where you should implement code to parse the packets from
            # the engine and act on it. We are just printing it instead.
            print data
            print ""

            split_data = data.split(' ')
            packet_type = split_data[0]

            if packet_type == "GETACTION":
                pot_size = split_data[1]
                num_board_cards = int(split_data[2])
                data_pointer = 3
                board_cards = split_data[data_pointer:data_pointer+num_board_cards]
                data_pointer += num_board_cards
                num_last_actions = int(split_data[data_pointer])
                data_pointer += 1
                last_actions = split_data[data_pointer:data_pointer+num_last_actions]
                data_pointer += num_last_actions
                num_legal_actions = int(split_data[data_pointer])
                data_pointer += 1
                legal_actions = split_data[data_pointer:data_pointer+num_legal_actions]

                if just_discarded:
                    for i in range(len(last_actions)):
                        act = last_actions[len(last_actions)-i-1]
                        if "DISCARD" in act and m_name in act:
                            spl = act.split(':')
                            old_card = spl[1]
                            new_card = spl[2]

                            hand.remove(old_card)
                            hand.append(new_card)
                            just_discarded = False
                            break

                print "POT SIZE:\t", pot_size
                #print "YOUR CHIPS:\t", bank
                print "HAND:\t\t", hand
                print "BOARD CARDS:\t", board_cards
                print "LAST ACTIONS:\t", last_actions
                print "LEGAL ACTIONS:\t", legal_actions
                
                # Get user input for action
                action = raw_input("What is your move " + m_name + "? : ")
                action += '\n'

                if "EXIT" in action:
                    s.close()
                    sys.exit(0)

                if "DISCARD" in action:
                    just_discarded = True
                
                print ""
                s.send(action)
            elif packet_type == "NEWGAME":
                m_name = split_data[1]
                bank = int(split_data[3])
            elif packet_type == "NEWHAND":
                i_am_dealer = split_data[2]
                hand = split_data[3:5]
            elif packet_type == "REQUESTKEYVALUES":
                s.send("FINISH\n")
            elif packet_type == "HANDOVER":
                just_discarded = False
                print "----------------------------------------------------------------------------"
            else:
                print ""
            
        # Clean up the socket.
        s.close()

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='A Pokerbot.', add_help=False, prog='pokerbot')
    parser.add_argument('-h', dest='host', type=str, default='localhost', help='Host to connect to, defaults to localhost')
    # parser.add_argument('port', metavar='PORT', type=int, default=3001, help='Port on host to connect to')
    parser.add_argument('-p', dest='port', type=int, default=3001, help='Host to connect to, defaults to localhost')
    args = parser.parse_args()

    # Create a socket connection to the engine.
    print 'Connecting to %s:%d' % (args.host, args.port)
    try:
        s = socket.create_connection((args.host, args.port))
    except socket.error as e:
        print 'Error connecting! Aborting'
        exit()

    bot = Player()
    bot.run(s)
