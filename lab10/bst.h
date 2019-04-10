#ifndef BST_H
#define BST_H

#include "structures.h"

node* create_node();
node* create_new_tree(int);
node* add_value(node*, int);
node* find_value(int);
node* delete_value(int);
node* find_parent(node*, node*);
void inorder_traversal(node*);

#endif
