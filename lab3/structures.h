#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Node {
	struct Node *next;
	long long int data;
} node;

typedef struct {
	long long int task_id;
	int priority;
} task;

typedef struct {
	node *head;	
	node *tail;
} queue;

typedef struct {
	queue *q;
	int num;
} multi_queue;

#endif
