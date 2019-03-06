#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

int globalCounter; // for keeping track of heap memory.

// Don't change the given structure definitions.

typedef struct student * Student;
struct student
{
	char * name;
	float marks;
};

typedef struct node * Node;
struct node
{
	Student record;
	Node next;
};


typedef struct list * List;
struct list
{
	int count;
	Node first;
	Node last;
};

// Implement each of these functions in List.c. 
// Don't change signatures and return types of these functions.
// You can add more functions as required.

Node createNode(Student record);

List createList(Student studArray, int arraySize);

void insertInOrder(List list, Node newNode);

List insertionSort(List list);

Node mergeSort(Node list);
Node mergeSortedList(Node a, Node b);
void splitHalf(Node head, Node *a, Node *b);

double measureSortingTime(List list);

void * myalloc(int size);

void myfree(void* ptr);
