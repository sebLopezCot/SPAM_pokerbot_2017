from deuces import Evaluator
from deuces import Card
import time 
import os

#Order: H: 1, S: 2, C:3, D:4

evaluator = Evaluator()
suits = ["h", "s", "c", "d"]
card_order = [] 

for i in range(2, 10):
    for suit in suits:
        card_order.append(Card.new(str(i)+suit))
for suit in suits:
    card_order.append(Card.new("T"+suit))
for suit in suits:
    card_order.append(Card.new("J"+suit))
for suit in suits:
    card_order.append(Card.new("Q"+suit))
for suit in suits:
    card_order.append(Card.new("K"+suit))
for suit in suits:
    card_order.append(Card.new("A"+suit))
Card.print_pretty_cards(card_order)

'''

board_hands = []
total = 0
for a in range(48):
	for b in range(a+1, 49):
		for c in range(b+1,  50):
			print(total)
			for d in range(c+1, 51):
				for e in range(d+1, 52):
					total+=1
					suit_array = [0, 0, 0, 0]
					board_num = (a ,b ,c,d,e)
					for num in board_num:
						suit_array[num%4] += 1
					if(suit_array[0]>=suit_array[1] and suit_array[1]>=suit_array[2] and suit_array[2]>=suit_array[3]):
						start_time = time.time()
						board_num = (a ,b ,c,d,e)
						board = []
						board.append(card_order[a])
						board.append(card_order[b])
						board.append(card_order[c])
						board.append(card_order[d])
						board.append(card_order[e])
						deck = range(52)
						deck.remove(a)
						deck.remove(b)
						deck.remove(c)
						deck.remove(d)
						deck.remove(e)
						possible_hands = []
						for i in range(46):
							for j in range(i+1, 47):
								possible_hands.append(((deck[i],deck[j]),evaluator.evaluate(board, [card_order[deck[i]], card_order[deck[j]]])))
						sorted_hands = sorted(possible_hands, key=lambda x: x[1] )
						hand_value = {}
						for i in range(len(sorted_hands)):
							hand_value[sorted_hands[i][0]] = i		
						f = open(str(a)+","+str(b)+","+str(c)+","+str(d)+","+str(e), "w")
#						hand_value_array = []
						for hand in hand_value:
							f.write(str(hand[0])+","+str(hand[1])+ " "+str(hand_value[hand])+"\n")
						f.close()
						
'''

'''


a = 0 
b= 1
c = 2 
d = 3
e = 4
start_time = time.time()
board_num = (a ,b ,c,d,e)
board = []
board.append(card_order[a])
board.append(card_order[b])
board.append(card_order[c])
board.append(card_order[d])
board.append(card_order[e])
deck = range(52)
deck.remove(a)
deck.remove(b)
deck.remove(c)
deck.remove(d)
deck.remove(e)
possible_hands = []
for i in range(46):
	for j in range(i+1, 47):
		possible_hands.append(((deck[i],deck[j]),evaluator.evaluate(board, [card_order[deck[i]], card_order[deck[j]]])))
sorted_hands = sorted(possible_hands, key=lambda x: x[1] )
hand_value = {}
for i in range(len(sorted_hands)):
	hand_value[sorted_hands[i][0]] = i		
#possible_river_hands[board_num] = hand_value
print(time.time()-start_time)
print(hand_value[(5,6)])

os.makedirs(str((a,b,c,d,e)))
for hand in hand_value:
	f = open(str((a,b,c,d,e))str(hand), "w")
	f.write(str(hand_value[hand]))
'''
'''
start_time = time.time()
f = open("0,1,2,3,4","r")
	hand_value = {}
for i in range(1081):
	hand_string = f.readline()
	hand_string_separate = hand_string.split()
	only_hand = hand_string_separate[0].split(",")
	hand_value[(int(only_hand[0]), int(only_hand[1]))] = int(hand_string_separate[1])
print(hand_value[(6,7)])
print(time.time()-start_time)
'''

count = 0
possible_river_hands = {}
for filename in os.listdir("River"):
	f = open("River/"+filename, "r")
	count+=1
	if(count%100 ==0):
		print(count)
	hand_value = []
	for i in range(1081):
		hand_string = f.readline()
		hand_string_separate = hand_string.split()
		only_hand = hand_string_separate[0].split(",")
		hand_value.append([int(only_hand[0]), int(only_hand[1]), int(hand_string_separate[1])])
	play_string = filename.split(",")
	play_tuple = (int(play_string[0]), int(play_string[1]), int(play_string[2]), int(play_string[3]), int(play_string[4]))
	possible_river_hands[play_tuple] = hand_value

	



for a in range(49):
	for b in range(a+1, 50):
		for c in range(b+1,  51):
			for d in range(c+1, 52):
				suit_array = [0, 0, 0, 0]
				board_num = (a ,b ,c,d)
				for num in board_num:
					suit_array[num%4] += 1
				if(suit_array[0]>=suit_array[1] and suit_array[1]>=suit_array[2] and suit_array[2]>=suit_array[3]):
					start_time = time.time()
					deck = range(52)
					deck.remove(a)
					deck.remove(b)
					deck.remove(c)
					deck.remove(d)
					possible_hands = {}
					start = time.time()
					for i in range(47):
						for j in range(i+1, 48):
							hand_value_inner = 0
							deck_copy = deck[:]
							card1 = deck[i]
							card2 = deck[j]
							deck_copy.remove(card1)
							deck_copy.remove(card2)
							for k in range(46):
								suit_array = [[0,0], [0,1], [0,2], [0,3]]
								board_num = (a ,b ,c,d, deck_copy[k])
								for num in board_num:
										suit_array[num%4][0] += 1	
								suit_array_sorted = sorted(suit_array, key = lambda x: x[0], reverse=True)
								old_cards = (card1, card2,a, b,c,d,deck_copy[k])
								new_cards = []
								for card in old_cards:
									card_suit = 0
									for m in range(4):
										if(card%4 == suit_array_sorted[m][1]):
											card_suit = m
									new_cards.append((card/4)*4+card_suit)
								sorted_board = sorted((new_cards[2],new_cards[3],new_cards[4],new_cards[5],new_cards[6]))
								sorted_hand = sorted((new_cards[0], new_cards[1]))
								hand_value_inner += possible_river_hands[(sorted_board[0],sorted_board[1],sorted_board[2],sorted_board[3],sorted_board[4])][(sorted_hand[0], sorted_hand[1])]
							possible_hands[(card1,card2)] = hand_value_inner/46
					f = open("Turn/"+str(a)+","+str(b)+","+str(c)+","+str(d), "w")
					for hand in possible_hands:
						f.write(str(hand[0])+","+str(hand[1])+ " "+str(possible_hands[hand])+"\n")
					f.close()
					print(time.time()-start)

'''
'''
'''
possible_turn_hands_discard = {}
for a in range(49):
	for b in range(a+1, 50):
		for c in range(b+1,  51):
			for d in range(c+1, 52):
				start_time = time.time()
				deck = range(52)
				deck.remove(a)
				deck.remove(b)
				deck.remove(c)
				deck.remove(d)
				possible_hands = {}
				for i in range(47):
						for j in range(i+1, 48):
							deck_copy = deck[:]
							card1 = deck[i]
							card2 = deck[j]
							deck_copy.remove(card1)
							deck_copy.remove(card2)
							no_discard = possible_turn_hands[(a,b,c,d)][(card1, card2)]
							discard_1 = 0 
							deck_copy.append(card1)
							for k in range(len(deck_copy)):
								discard_1 += possible_turn_hands[(a,b,c,d)][(deck_copy[k], card2)]
							discard_1 /= len(deck_copy)
							deck_copy.remove(card1)
							discard_2 = 0 
							deck_copy.append(card2)
							for k in range(len(deck_copy)):
								discard_2 += possible_turn_hands[(a,b,c,d)][(card1, deck_copy[k])]
							discard_2 /= len(deck_copy)
							deck_copy.remove(card2)	
							if(no_discard > discard_1 and discard_2):
								possible_hands[(card1, card2)] = (no_discard, 0)
							elif(discard_1>discard_2):
								possible_hands[(card1, card2)] = (discard_1, 1)
							else:
								possible_hands[(card1, card2)] = (discard_2, 2)
				possible_turn_hands_discard[(a,b,c,d)] = possible_hands



possible_flop_hands = {}
for a in range(50):
	for b in range(a+1, 51):
		for c in range(b+1,  52):
			start_time = time.time()
			deck = range(52)
			deck.remove(a)
			deck.remove(b)
			deck.remove(c)
			possible_hands = {}
			for i in range(49):
					for j in range(i+1, 48):
						hand_value = 0 
						card1 = deck[i]
						card2 = deck[j]
						deck_copy = deck[:]
						deck.remove(i)
						deck.remove(j)
						for k in range(47):
							key = sorted((a,b,c,deck[k]))
							hand_value += possible_turn_hands_discard[key[(a,b,c)][0]
						possible_hands[(card1, card2)] = hand_value/=46


possible_flop_hands_discard = {}
for a in range(50):
	for b in range(a+1, 51):
		for c in range(b+1,  52):
			start_time = time.time()
			deck = range(52)
			deck.remove(a)
			deck.remove(b)
			deck.remove(c)
			possible_hands = {}
			for i in range(48):
					for j in range(i+1, 49):
						deck_copy = deck[:]
						card1 = deck[i]
						card2 = deck[j]
						deck_copy.remove(card1)
						deck_copy.remove(card2)
						no_discard = possible_flop_hands[(a,b,c)][(card1, card2)]
						discard_1 = 0 
						deck_copy.append(card1)
						for k in range(len(deck_copy)):
							discard_1 += possible_flop_hands[(a,b,c)][(deck_copy[k], card2)]
						discard_1 /= len(deck_copy)
						deck_copy.remove(card1)
						discard_2 = 0 
						deck_copy.append(card2)
						for k in range(len(deck_copy)):
							discard_2 += possible_flop_hands[(a,b,c)][(card1, deck_copy[k])]
						discard_2 /= len(deck_copy)
						deck_copy.remove(card2)	
						if(no_discard > discard_1 and discard_2):
							possible_hands[(card1, card2)] = (no_discard, 0)
						elif(discard_1>discard_2):
							possible_hands[(card1, card2)] = (discard_1, 1)
						else:
							possible_hands[(card1, card2)] = (discard_2, 2)
			possible_turn_hands_discard[(a,b,c)] = possible_hands
'''