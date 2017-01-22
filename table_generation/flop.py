import os 

count = 0
possible_turn_discard_hands = {}
for filename in os.listdir("Turn_Discard"):
	f = open("Turn_Discard/"+filename, "r")
	count+=1
	if(count%100 ==0):
		print(count)
	hand_value = {}
	for i in range(47*48/2):
		hand_string = f.readline()
		hand_string_separate = hand_string.split()
		only_hand = hand_string_separate[0].split(",")
		hand_value[(int(only_hand[0]), int(only_hand[1]))] =  int(hand_string_separate[1])
	play_string = filename.split(",")
	play_tuple = (int(play_string[0]), int(play_string[1]), int(play_string[2]), int(play_string[3]))
	possible_turn_discard_hands[play_tuple] = hand_value



for a in range(50):
	for b in range(a+1, 51):
		for c in range(b+1,  52):
			suit_array = [0, 0, 0, 0]
			board_num = (a ,b ,c)
			for num in board_num:
				suit_array[num%4] += 1
			if(suit_array[0]>=suit_array[1] and suit_array[1]>=suit_array[2] and suit_array[2]>=suit_array[3]):
				count+=1 
				deck = range(52)
				deck.remove(a)
				deck.remove(b)
				deck.remove(c)
				possible_hands = {}
				for i in range(48):
					for j in range(i+1, 49):
						hand_value_inner = 0
						deck_copy = deck[:]
						card1 = deck[i]
						card2 = deck[j]
						deck_copy.remove(card1)
						deck_copy.remove(card2)
						for k in range(47):
							suit_array = [[0,0], [0,1], [0,2], [0,3]]
							board_num = (a ,b ,c, deck_copy[k])
							for num in board_num:
									suit_array[num%4][0] += 1	
							suit_array_sorted = sorted(suit_array, key = lambda x: x[0], reverse=True)
							old_cards = (card1, card2,a, b,c,deck_copy[k])
							new_cards = []
							for card in old_cards:
								card_suit = None
								for m in range(4):
									if(card%4 == suit_array_sorted[m][1]):
										card_suit = m
										break
								new_cards.append((card/4)*4+card_suit)
							sorted_board = sorted((new_cards[2],new_cards[3],new_cards[4],new_cards[5]))
							sorted_hand = sorted((new_cards[0], new_cards[1]))
							hand_value_inner += possible_turn_discard_hands[(sorted_board[0],sorted_board[1],sorted_board[2],sorted_board[3])][(sorted_hand[0], sorted_hand[1])]
						possible_hands[(card1,card2)] = hand_value_inner/47
				average= sum(possible_hands.values())/(len(possible_hands))
				for hand in possible_hands:
					if(possible_hands[hand] > 0):
							possible_hands[hand] = (possible_hands[hand]*1080)/average
				f = open("Flop/"+str(a)+","+str(b)+","+str(c), "w")
				for hand in possible_hands:
					f.write(str(hand[0])+","+str(hand[1])+ " "+str(possible_hands[hand])+"\n")
				f.close()