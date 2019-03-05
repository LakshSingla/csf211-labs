#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

extern int globalCounter;

Node createNode(Student record) {
	Node n = (Node)myalloc(sizeof(struct node));
	if(n == NULL) {
		printf("Unable to reserve space for new node");
	}
	n->record = record;
	n->next = NULL;
	return n;
}	

List createList(Student studArray, int arraySize) {
	List l = (List)myalloc(sizeof(struct list));
	if(l == NULL) {
		printf("Unable to reserve space for list");
	}
	l->count = arraySize;
	Node prev = NULL;
	for(int i = 0; i < arraySize; ++i) {
		Node n = createNode(studArray + i);
		
		if(prev) prev->next = n;
		
		if(i == 0) l->first = n;
		else if (i == arraySize - 1) { 
			l->last = n;
			n->next = NULL; 
		}
			
		prev = n;	
	}
	
	return l;
}

void* myalloc(int size) {
	void *x = malloc(size + sizeof(int));
	if(x == NULL) {
		printf("Unable to allocate space\n");
		exit(0);
	}
	*(int*)x = size;
	globalCounter += size;
	return (void*)((char*)x + sizeof(int));
}

void myfree (void *ptr) {
	void *y = (char*)ptr - sizeof(int);
	int memSize = *(int*)y;
	globalCounter -= memSize;
	free(y);
}

void insertInOrder(List list, Node newNode) {
	int count = list->count;
	Node head = list->first;
	
	//Case of empty list
	if(head == NULL || count == 0){
	 list->count = 1;
	 list->first = list->last = newNode;
	 newNode->next = NULL;
	 return;
	}
	
	//Increment the list count as we are inserting one more element
	++(list->count);
	//Case where head has to change
	if (head->record->marks >= newNode->record->marks) {
		newNode->next = list->first;
		list->first = newNode;
		return;
	}
	
	else {
		Node prev = list->first;
		Node cur = prev->next;
		while(cur && cur->record->marks < newNode->record->marks) {
			prev = prev->next;
			cur = cur->next;
		}
		
		prev->next = newNode;
		newNode->next = cur;		
		
		//Insertion at the last
		if(!cur) list->last = newNode;
		 
		return;
	}
}

List insertionSort(List list) {
	List sortedList = (List)myalloc(sizeof(struct list));
	sortedList->count = 0;
	sortedList->first = NULL;
	sortedList->last = NULL;
	
	Node head = list->first;
	while(head) {
		Node headClone = (Node)myalloc(sizeof(struct node));
		headClone->record = head->record;
		headClone->next = head->next;
		insertInOrder(sortedList, headClone);
		Node prev = head;
		head = head->next;
		myfree(prev);
	}
	
	return sortedList;
}

double measureSortingTime(List list) {
	double elapsedTime;
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	insertionSort(list);
	gettimeofday(&t2, NULL);	
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000;	
	return elapsedTime;
}
