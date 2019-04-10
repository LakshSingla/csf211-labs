#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct _node {
	int value;
	struct _node *left;
	struct _node *right;
	int hb;
} node;

#endif
