#ifndef MULTI_QUEUE_H 
#define MULTI_QUEUE_H 

#include <stdbool.h>

#include "structures.h"

multi_queue create_multi_queue(int);
void add_in_mq(multi_queue*, task);
task del_next_mq(multi_queue*);
task next_mq(multi_queue*);
int size_mq(multi_queue*);
int size_mq_by_priority(multi_queue *mq, int p);
queue *get_q_from_mq(multi_queue *mq, int p);
bool is_mq_empty(multi_queue*);
void print_mq(multi_queue*);

#endif
