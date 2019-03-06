#include "create_list.h"
#include "structures.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


node* create_list(unsigned long long int N) {
	node *cur, *prev;
	node *head = NULL;
	cur = prev = NULL;
	int is_head = 1;
	while(N--) { 
		cur = malloc(sizeof(node));
		cur->data = rand();
		cur->next = NULL;
		if(is_head) {
			head = cur;
			is_head = 0;
			
		}
		if(prev != NULL) prev->next = cur;
		prev = cur;
	}
	return head;
}

node *create_cycle(node *list) {
	if(list == NULL) return list;
	if(rand() % 2) {
		printf("NO CYCLE\n");
		return list;			
	}
	node *tail = list;
	if(tail == NULL) { 
		printf("EMPTY LIST\n");
		return list;	
	}
	printf("CYCLE");

	int n = 1;

	node *next = tail->next;
	while(next != NULL) {
		++n;
		tail = tail->next;	
		next = next->next;	
	}

	int cycle_head = rand() % n;
	printf(", Head = %d\n", cycle_head);
	node* cycle_head_ptr = list;

	while(cycle_head--) 
		cycle_head_ptr = cycle_head_ptr->next;	
	
	tail->next = cycle_head_ptr;

	return list;
}
