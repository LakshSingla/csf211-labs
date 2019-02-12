#include "test_cycle.h"
#include "structures.h"

#include <stdio.h>

void cycle1(node *list) {
	if(list == NULL) return;

	node *hare, *tort;
	hare = tort = list;

	while(1) {
		if(hare->next == NULL) {
			printf("NO CYCLE\n");
			break;
		}
		if(hare->next->next == NULL) {
			printf("NO CYCLE\n");
			break;
		}
		hare = hare->next->next;
		tort = tort->next;
		if(hare == tort) {
			printf("CYCLE\n");
			break;
		}
	}
}

node* cycle2(node *list) {
	if(list == NULL) return list;
	node *prev = NULL;
	node *cur = list;	

	while(cur != NULL) {
		node *fwd = cur->next;
		cur->next = prev;
		prev = cur;
		cur = fwd;
	}
	return prev;
}
