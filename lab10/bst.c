#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

node* create_node() {
	node *new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL) {
		printf("Unable to allocate memory for new node. Exiting...\n");	
		exit(0);
	}
	return new_node;
}

node* create_new_tree(int value) {
	node *new_node = create_node();
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->hb = 0;
	return new_node;
}

node *add_value(int value) {
	node *new_node = create_node();	
	while(true) {
			
	}
}

void inorder_traversal(node *tree) {
	if(tree == NULL) return;
	inorder_traversal(tree->left);
	printf("%d ", tree->value);
	inorder_traversal(tree->right);
}
