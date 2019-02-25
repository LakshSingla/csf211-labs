#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

cards_info read_file(const char *filename) {
	FILE *fp = fopen(filename, "r");	
	if(fp == NULL) {
		exit(0);
	}

	int size = 100;
	int len = 0;
	credit_card *cards = malloc(sizeof(credit_card) * size);
	if(cards == NULL) {
		printf("Unable to allocate memory for %d records. Exiting...\n", size);
		exit(0);
	}
	credit_card card;

	const char *fstring = " \"%llu,%5c,%2hu/%4d,%[^\,],%[^\"]\"";
	while(fscanf(fp, fstring, &(card.card_no), card.bank_code, &(card.expiry_date.month), &(card.expiry_date.year), card.first_name, card.last_name) != EOF) {
		++len;
		if(len > size) {
			size = size * 2;	
			cards = realloc(cards, sizeof(credit_card) * size);
			if(cards == NULL) {
				printf("Unable to allocate memory for %d records. Exiting...\n", size);
				exit(0);
			}
		}
		cards[len-1] = card;
	}

	fclose(fp);

	cards_info c = { 
		.start_value = cards,
		.length = len
	};
	return c;

	/*return struct {
		.start_value = cards;	
		.length = len;
	};*/
}
