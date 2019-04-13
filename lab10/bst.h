#ifndef BST_H
#define BST_H

#include "structures.h"

node* create_node();
node* add_value(node*, int);
node* find_value(node*, int);
node* delete_value(node*, node*);
node* find_parent(node*, node*);
node* find_min(node*);
node* find_successor(node*, node*);
void inorder_traversal(node*);
int update_heights(node*);
int find_height(node*);
void update_height_balance(node*);

#endif
