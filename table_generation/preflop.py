import os

possible_flop_discard_hands_b = {}
for filename in os.listdir("Flop_Before_Discard"):
	f = open("Flop_Before_Discard/"+filename, "r")
	hand_value = {}
	for i in range(49*48/2):
		hand_string = f.readline()
		hand_string_separate = hand_string.split()
		only_hand = hand_string_separate[0].split(",")
		hand_value[(int(only_hand[0]), int(only_hand[1]))] =  int(hand_string_separate[1])
	play_string = filename.split(",")
	play_tuple = (int(play_string[0]), int(play_string[1]), int(play_string[2]))
	possible_flop_discard_hands_b[play_tuple] = [hand_value, 0]

for a in range(50):
	for b in range(a+1,51):
		for c in range(b+1, 51):
			suit_array = [[0,0], [0,1], [0,2], [0,3]]
			board_num = (a ,b ,c)
			for num in board_num:
				suit_array[num%4][0] += 1	
			suit_array_sorted = sorted(suit_array, key = lambda x: x[0], reverse=True)
			old_cards = (a, b, c)
			new_cards = []
			for card in old_cards:
				card_suit = 0
				for m in range(4):
					if(card%4 == suit_array_sorted[m][1]):
						card_suit = m
						break
				new_cards.append((card/4)*4+card_suit)
			sorted_new_cards = sorted(new_cards)
			possible_flop_discard_hands_b[(sorted_new_cards[0], sorted_new_cards[1], sorted_new_cards[2])][1] += 1 

possible_flop_discard_hands = {}
for flop in possible_flop_discard_hands_b:
	times = possible_flop_discard_hands_b[flop][1]
	new_flop = {}
	for hand in possible_flop_discard_hands_b[flop][0]:
		new_flop[hand] =(possible_flop_discard_hands_b[flop][0][hand])*times
	possible_flop_discard_hands[flop] = new_flop
			

preflop = {}
for i in range(51):
	for j in range(i+1, 52):
		preflop[(i,j)] = [0, 0]
count = 0
for flop in possible_flop_discard_hands:
	count += 1 
	if(count%100 ==0):
		print(count)
	for hand in possible_flop_discard_hands[flop]:
		preflop[hand][0] += possible_flop_discard_hands[flop][hand]
		preflop[hand][1] += 1 

for hand in preflop:
	preflop[hand][0] = float(preflop[hand][0])/preflop[hand][1]

total = 0 
count = 0 
for hand in preflop:
	total += preflop[hand][0]
	count += 1 

for hand in preflop:
	preflop[hand][0] = preflop[hand][0]/(total/count)*540
#Same suit different number 
for i in range(12):
	for j in range(i+1,13):
		total = 0 
		total += preflop[(i*4,j*4)][0]
		total += preflop[(i*4+1,j*4+1)][0]
		total += preflop[(i*4+2,j*4+2)][0]
		total += preflop[(i*4+3,j*4+3)][0]
		preflop[(i*4,j*4)][0] = total/4
		preflop[(i*4+1,j*4+1)][0] = total/4
		preflop[(i*4+2,j*4+2)][0] = total/4
		preflop[(i*4+3,j*4+2)][0] = total/4
#Different suit different number 

for i in range(12):
	for j in range(i+1,13):
		total = 0 
		total += preflop[(i*4,j*4+1)][0]
		total += preflop[(i*4,j*4+2)][0]
		total += preflop[(i*4,j*4+3)][0]
		total += preflop[(i*4+1,j*4)][0]
		total += preflop[(i*4+1,j*4+2)][0]
		total += preflop[(i*4+1,j*4+3)][0]
		total += preflop[(i*4+2,j*4)][0]
		total += preflop[(i*4+2,j*4+1)][0]		
		total += preflop[(i*4+2,j*4+3)][0]
		total += preflop[(i*4+3,j*4)][0]
		total += preflop[(i*4+3,j*4+1)][0]		
		total += preflop[(i*4+3,j*4+2)][0]
		total/= 12
		preflop[(i*4,j*4+1)][0] = total 
		preflop[(i*4,j*4+2)][0] = total
		preflop[(i*4,j*4+3)][0] = total
		preflop[(i*4+1,j*4)][0]= total 
		preflop[(i*4+1,j*4+2)][0]= total 
		preflop[(i*4+1,j*4+3)][0]= total 
		preflop[(i*4+2,j*4)][0]= total 
		preflop[(i*4+2,j*4+1)][0]= total 		
		preflop[(i*4+2,j*4+3)][0]= total 
		preflop[(i*4+3,j*4)][0]= total 
		preflop[(i*4+3,j*4+1)][0]= total 		
		preflop[(i*4+3,j*4+2)][0]= total 

#Same number different suit 
for i in range(13):
	total = 0 
	total += preflop[(i*4, i*4+1)][0]
	total += preflop[(i*4, i*4+2)][0]
	total += preflop[(i*4, i*4+3)][0]
	total += preflop[(i*4+1, i*4+2)][0]
	total += preflop[(i*4+1, i*4+2)][0]
	total += preflop[(i*4+2, i*4+3)][0]
	total/=6
	preflop[(i*4, i*4+1)][0] = total
	preflop[(i*4, i*4+2)][0] = total 
	preflop[(i*4, i*4+3)][0] = total
	preflop[(i*4+1, i*4+2)][0] = total
	preflop[(i*4+1, i*4+3)][0] = total
	preflop[(i*4+2, i*4+3)][0] = total

hand_list = [] 
for hand in preflop:
	hand_list.append((hand, preflop[hand][0]))

next_list = sorted(hand_list, key=lambda x: x[0][0]*52+x[0][1])


f = open("PreflopTable2", "w")
for hand_values in next_list:
	f.write(str(hand_values[0][0])+","+str(hand_values[0][1])+" "+str(hand_values[1]))
	f.write("\n")
