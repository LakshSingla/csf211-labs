#ifndef TREE_H 
#define TREE_H 

#include "structures.h"

#define MAX_DELIMS 20

node* create_new_tree();
node* add_data(node*, char*);
void print_data(const node*, int);

#endif
