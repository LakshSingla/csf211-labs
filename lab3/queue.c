#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"

queue create_queue() {
	queue x = {
		.head = NULL,	
		.tail = NULL
	};
	return x;
}

void insert_in_queue(queue *q, long long int data) {
	node *new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL) {
		printf("Unable to allocate space for another node. Exiting...\n");	
		exit(0);
	}
	new_node->data = data;
	new_node->next = NULL;
	if(is_queue_empty(q)) {
		q->head = new_node;	
		q->tail = new_node;	
		return;
	}
	q->tail->next = new_node;
	q->tail = new_node;
}

long long int peek(queue *q) {
	if(q == NULL) {
		printf("Enter a Queue pointer\n");	
		return -1;
	}
	if(is_queue_empty(q)) {
		printf("Queue underflow, cannot remove any more elements\n");
		return -1;
	}
	return q->head->data;
}

long long int deque(queue *q) {
	if(q == NULL) {
		printf("Enter a Queue pointer\n");	
		return -1;
	}
	if(is_queue_empty(q)) {
		printf("Queue underflow, cannot remove any more elements\n");
		return -1;
	}
	node *elem = q->head;
	q->head = elem->next;
	long long int val = elem->data;
	free(elem);
	return val;
}

void print_queue(queue *q) {
	if(q == NULL) {
		printf("Enter a Queue pointer\n");	
		return;
	}
	node *head = q->head;
	while(head != NULL) {
		printf("%lld\t", head->data);	
		head = head->next;
	}
	printf("\n");
}

bool is_queue_empty(queue *q) {
	if(q == NULL)
		printf("Enter a Queue pointer\n");	
	return (q->head == NULL);
}

long long int len_queue(queue* q) {
	if(q == NULL){
		printf("Enter a Queue pointer\n");	
		return -1;
	}
	long long int len = 0;
	node *head = q->head;
	while(head != NULL && ++len) head = head->next;
	return len;
}
