#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#include "structures.h"

queue create_queue();
void insert_in_queue(queue*, long long int);
void deque(queue *);
void print_queue(queue *);
bool is_queue_empty(queue*);

#endif
