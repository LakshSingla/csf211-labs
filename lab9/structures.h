#ifndef STRUCTURES_H
#define STRUCTURES_H

struct _node;

typedef struct {
	struct _node **ht;
	int element_count;
	int insertion_cost;
	int querying_cost;
} hash_table;

typedef struct _node {
	char *word;
	int index;
	int freq;
	struct _node *next;
} node;

#endif
