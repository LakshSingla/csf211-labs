#include "sort.h"
#include <stdio.h>

//Place denotes the index by which to insert
void insert_in_order(credit_card *cards, long long int place) {
	printf("%lld\n", place);
	for(long long int i = place; i >= 1; --i) {
		if(cards[i].card_no < cards[i-1].card_no) { 
			credit_card temp = cards[i];	
			cards[i] = cards[i-1];
			cards[i-1] = temp;
		}
	}
}

//Length denotes the length of the arra
void insertion_sort(credit_card *cards, long long int index, long long int length) {
	//if(index == length) return;

	for(long long int i = 0; i < length; ++i)
		insert_in_order(cards, i);

	//insert_in_order(cards, index);	//Place in order the last element
	//insertion_sort(cards, index+1, length);	//Decrease the length of the array to be sorted

	return;
}
