#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

	//Calculate generic height balance information
	node *current_node = new_node;
	node *parent_node = find_parent(tree, new_node);
	bool prev_changed = true;
	while(parent_node != NULL && prev_changed) {
		prev_changed = false;
		if(parent_node->left == current_node) {
			int current_hb = parent_node->hb;
			--current_hb;
			if(abs(parent_node->hb) < abs(current_hb)) {
				prev_changed = true;
				parent_node->hb = current_hb;
			}
		}
		else {
			int current_hb = parent_node->hb;
			++current_hb;
			if(abs(parent_node->hb) < abs(current_hb)) {
				prev_changed = true;
				parent_node->hb = current_hb;
			}
		}
		current_node = parent_node;
		parent_node = find_parent(tree, parent_node);
	}
	return tree;
}

node *delete_value(node *tree, node *to_delete) {
	printf("%d\t", to_delete->value);

	node *parent = find_parent(tree, to_delete);
	
	//No children of the node
	if(to_delete->left == NULL && to_delete->right == NULL) {
		bool was_left;
		if(parent == NULL) {
			free(to_delete);	
			return NULL;
		}

		if(parent->right == to_delete) {
			parent->right = NULL;
			was_left = false;
		}
		else {
			parent->left = NULL;
			was_left = true;
		}
		free(to_delete);

		//Height balance information change
		bool prev_changed = true;
		while(prev_changed && parent != NULL) {
			prev_changed = false;
			if(was_left && parent->hb < 0) {
				parent->hb++;
				prev_changed = true;
			}	 
			else if(!was_left && parent->hb > 0) {
				parent->hb--;		
				prev_changed = true;
			}
			node *temp = parent;
			parent = find_parent(tree, parent);
			parent && (was_left = (parent->left == temp));
		}
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
	printf("%d(%d) ", tree->value, tree->hb);
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
