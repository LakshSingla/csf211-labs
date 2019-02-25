#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct {
	unsigned long long int card_no;
	char bank_code[6];
	struct {
		short int month;	
		int year;	
	} expiry_date;
	char first_name[30];
	char last_name[30];
} credit_card;

typedef struct {
	credit_card *start_value;
	unsigned long long int length;
} cards_info;

#endif
