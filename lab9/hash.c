#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

int hash(char *str, int base_number, int table_size) {
	long long int x = 0;
	while(*str != 0) x += *(str++);
	x %= base_number;
	x %= table_size;
	int y = (int) x;	
	return y;
}

long long int collision(char **str_arr, int arr_length, int base_number, int table_size) {
	
	int *table = (int *)malloc(sizeof(int) * table_size);
	for(int i = 0; i < table_size; ++i) table[i] = -1;
	for(int i = 0; i < arr_length; ++i){
		table[hash(*str_arr++, base_number, table_size)] += 1;
	}

	long long int sum = 0;
	for(int i = 0; i < table_size; ++i) sum += (table[i] == -1 ? 0 : table[i]);

	free(table);
	return sum;
}

hash_table* create_new_hash_table(int table_size) {
	hash_table *x = (hash_table*)malloc(sizeof(hash_table));
	x->ht = (node**)malloc(sizeof(node*) * table_size);
	for(int i = 0; i < table_size; ++i) x->ht[i] = NULL;
	x->element_count = 0;
	x->insertion_cost = 0;
	x->querying_cost = 0;
	return x;
}

//Assume that the hash_table has full control of the function
hash_table* insert_in_hash_table(hash_table *x, char *word, int index, int base_number, int table_size) {
	int computed_hash = hash(word, base_number, table_size);
	node *chain = x->ht[computed_hash];
	node *trailing =  NULL;
	while(chain != NULL) {
		x->insertion_cost++;
		if(strcmp(word, chain->word) == 0) {
			chain->freq++;
			return x;
		}
		trailing = chain;
		chain = chain->next;
	}
	x->insertion_cost++;
	node *new_entry = (node*)malloc(sizeof(node));
	if(new_entry == NULL) {
		printf("Unable to allocate memory for a new node. Exiting...\n");	
		exit(0);
	}
	new_entry->word = word;
	new_entry->index = index;
	new_entry->freq = 1;
	new_entry->next = NULL;
	x->element_count++;
	if(trailing == NULL) {
		x->ht[computed_hash] = new_entry;
		return x;
	}
	trailing->next = new_entry;
	return x;
}

hash_table * insert_all_in_hash_table(hash_table *x, char **arr, int arr_length, int base_number, int table_size) {
	for(int i = 0; i < arr_length; ++i)
		insert_in_hash_table(x, arr[i], i, base_number, table_size);

	return x;
}

void print_frequency(hash_table *x, int table_size) {
	printf("%s\t\t%s\t\t\t%s\t\t%s\n", "HASH", "WORD", "INDEX", "FREQ");	
	for(int i = 0; i < table_size; ++i) {
		node *chain = x->ht[i];
		while(chain) {
			printf("%d\t\t%s\t\t\t%d\t\t%d\n", i, chain->word, chain->index, chain->freq);	
			chain = chain->next;
		}
	}
}

node *lookup(hash_table *x, char *word, int base_number, int table_size) {
	int computed_hash = hash(word, base_number, table_size);
	node *chain = x->ht[computed_hash];
	while(chain && strcmp(chain->word, word)) {
		x->querying_cost++;
		chain = chain->next;
	}
	if(chain)
		printf("word: %s, hash: %d, index: %d, freq: %d\n", chain->word, computed_hash, chain->index, chain->freq);	
	else
		printf("%s not found in the hash table\n", word);
	return chain;
}

void lookup_all(hash_table *x, char **arr, int arr_length, int base_number, int table_size) {
		for(int i = 0; i < arr_length; ++i)
			lookup(x, arr[i], base_number, table_size);
}
