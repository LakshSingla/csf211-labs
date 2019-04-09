#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct _node {
	char *key;
	char *ip;
	struct _node *first_child;
	struct _node *right_sibling;
} node;

#endif
