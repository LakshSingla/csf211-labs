#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "structures.h"

queue create_queue();
void insert_in_queue(queue*, long long int);
long long int peek(queue*);
long long int deque(queue *);
void print_queue(queue *);
bool is_queue_empty(queue*);
long long int len_queue(queue*);

#endif
