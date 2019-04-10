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

node *add_value(node* tree, int value) {
	node *new_node = create_node();	
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->hb = 0;

	//In case, no tree is present, create a new tree and return it;
	if(tree == NULL) return new_node;

	node *cur = tree;
	while(true){
		if(cur->value > value) {
			if(cur->left == NULL) {
				cur->left = new_node;
				break;
			}	
			cur = cur->left;
			continue;
		}
		else {
			if(cur->right == NULL) {
				cur->right = new_node;	
				break;
			}
			cur = cur->right;
			continue;
		}
	}
	return tree;
}

node *delete_value(node *tree, node *to_delete) {

	node *parent = find_parent(tree, to_delete);
	
	//No children of the node
	if(to_delete->left == NULL && to_delete->right == NULL) {
		if(parent == NULL) {
			free(to_delete);	
			return NULL;
		}

		if(parent->right == to_delete) parent->right = NULL;
		else parent->left = NULL;
		free(to_delete);
		return tree;
	}

	//Single child of the node, right child present
	if(to_delete->left == NULL && to_delete->right != NULL) {
		if(parent == NULL) {
			node *new_tree_root = to_delete->right;
			free(to_delete);		
			return new_tree_root;
		}
		if(parent->left == to_delete) parent->left = to_delete->right;
		else parent->right = to_delete->right;
		free(to_delete);
		return tree;
	}

	//Single child of the node, left child present
	if(to_delete->left != NULL && to_delete->right == NULL) {
		if(parent == NULL) {
			node *new_tree_root = to_delete->left;
			free(to_delete);		
			return new_tree_root;
		}
		if(parent->left == to_delete) parent->left = to_delete->left;
		else parent->right = to_delete->left;
		free(to_delete);
		return tree;
	}

	node* succ_node = find_successor(tree, to_delete);
	to_delete->value = succ_node->value;
	return delete_value(tree, succ_node);
}

node* find_value(node *tree, int value) {
	//Shortcircuiting will ensure that we donot access invalid memory location
	if(tree == NULL || tree->value == value) return tree;
	else if(tree->value > value) return find_value(tree->left, value);
	return find_value(tree->right, value);
}

void inorder_traversal(node *tree) {
	if(tree == NULL) return;
	inorder_traversal(tree->left);
	printf("%d ", tree->value);
	inorder_traversal(tree->right);
}

node* find_parent(node *tree, node *child) {
	//Empty tree or tree is the parent node
	if(tree == NULL || tree == child) return NULL;
	else if(tree->left == child || tree->right == child) return tree;

	if(tree->value > child->value) return find_parent(tree->left, child);
	else if(tree->value < child->value) return find_parent(tree->right, child);
	//In case of multiple keys, one may need to search for both
	//left and right subtrees, thus need to backtrack
	else {
		node *maybe_left_child;
		maybe_left_child = find_parent(tree->left, child);
		if(maybe_left_child) return maybe_left_child;
		else return find_parent(tree->right, child);
	}
}

//Finds the minimum of a tree rooted at "tree"
node* find_min(node *tree) {
	if(tree == NULL || tree->left == NULL) return tree;	
	return find_min(tree->left);
}

//Finds the successor of the node rooted at "n"
node* find_successor(node* tree, node *n) {
	if(n == NULL) return NULL;

	if(n->right) return find_min(n->right);

	node *ansc = n;
	node *parent_ansc = find_parent(tree, ansc);
	while(parent_ansc != NULL && parent_ansc->left != ansc) {
		ansc = parent_ansc;
		parent_ansc = find_parent(tree, parent_ansc);
	}
	return parent_ansc;
}
