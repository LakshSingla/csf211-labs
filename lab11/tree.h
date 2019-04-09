#ifndef TREE_H 
#define TREE_H 

#include "structures.h"

#define MAX_DELIMS 20

node* create_new_tree();
node* add_hostname(node*, char*, char*);
void print_data(const node*, int);

#endif
