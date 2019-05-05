#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "avl.h"

node* create_node() {
	node *new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL) {
		printf("Unable to allocate memory for new node. Exiting...\n");	
		exit(0);
	}
	return new_node;
}

node *add_value(node* tree, int value) {
	printf("%d\t", value);
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
	/*node *current_node = new_node;
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
	}*/
	//update_heights(tree);
	update_height_balance(tree);

	node *trailing = new_node;
	node *trailing1 = find_parent(tree, trailing);
	node *trailing2 = find_parent(tree, trailing1);
	node *new_tree = tree;
	//printf("%p\t%p\t%p\t%p\n", trailing, trailing1, trailing2, new_tree);

	while(trailing2) {
		node *temp1 = trailing1;
		node *temp2 = trailing2;
		node *temp3 = find_parent(tree, temp2);
		if(abs(trailing2->hb2) > 1) {
			if(trailing2->left == trailing1) {
				if(trailing1->left == trailing) {
					//printf("L->L");
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
				else {
					//printf("L->R");
					new_tree = rotate(new_tree, trailing1, trailing);
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
			}	

			if(trailing2->right == trailing1) {
				if(trailing1->left == trailing) {
					//printf("R->L");
					new_tree = rotate(new_tree, trailing1, trailing);
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
				else {
					//printf("R->R");
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
			}	
		}
		trailing = temp1;
		trailing1 = temp2;
		trailing2 = temp3;
	}
	update_height_balance(new_tree);
	return new_tree;
}

node *delete_value(node *tree, node *to_delete) {
	node *new_tree_root;
	printf("%d\t", to_delete->value);
	node *parent = find_parent(tree, to_delete);
	bool left_deleted = false;
	
	//No children of the node
	if(to_delete->left == NULL && to_delete->right == NULL) {
		if(parent == NULL) {
			free(to_delete);	
			return NULL;
		}

		if(parent->right == to_delete) {
			parent->right = NULL;
			left_deleted = false;
		}
		else {
			parent->left = NULL;
			left_deleted = true;
		}
		free(to_delete);
		new_tree_root = tree;

		//Height balance information change
		/*bool prev_changed = true;
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
		}*/
	}

	//Single child of the node, right child present
	else if(to_delete->left == NULL && to_delete->right != NULL) {
		if(parent == NULL) {
			new_tree_root = to_delete->right;
			free(to_delete);	
		}
		if(parent->left == to_delete) parent->left = to_delete->right;
		else parent->right = to_delete->right;
		free(to_delete);
		new_tree_root = tree;
	}

	//Single child of the node, left child present
	else if(to_delete->left != NULL && to_delete->right == NULL) {
		if(parent == NULL) {
			new_tree_root = to_delete->left;
			free(to_delete);		
		}
		if(parent->left == to_delete) parent->left = to_delete->left;
		else parent->right = to_delete->left;
		free(to_delete);
		new_tree_root = tree;
	}

	else {
		node* succ_node = find_successor(tree, to_delete);
		to_delete->value = succ_node->value;
		new_tree_root = delete_value(tree, succ_node);
	}

	//printf("Update heights being called...\n");
	//update_heights(tree);
	update_height_balance(tree);

	/*node *trailing = new_node;
	node *trailing1 = find_parent(tree, trailing);
	node *trailing2 = find_parent(tree, trailing1);
	node *new_tree = tree;
	//printf("%p\t%p\t%p\t%p\n", trailing, trailing1, trailing2, new_tree);

	while(trailing2) {
		node *temp1 = trailing1;
		node *temp2 = trailing2;
		node *temp3 = find_parent(tree, temp2);
		if(abs(trailing2->hb2) > 1) {
			if(trailing2->left == trailing1) {
				if(trailing1->left == trailing) {
					//printf("L->L");
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
				else {
					//printf("L->R");
					new_tree = rotate(new_tree, trailing1, trailing);
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
			}	

			if(trailing2->right == trailing1) {
				if(trailing1->left == trailing) {
					//printf("R->L");
					new_tree = rotate(new_tree, trailing1, trailing);
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
				else {
					//printf("R->R");
					new_tree = rotate(new_tree, trailing2, trailing1);
				}
			}	
		}
		trailing = temp1;
		trailing1 = temp2;
		trailing2 = temp3;
	}*/
	//update_height_balance(new_tree);
	return new_tree_root;
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
	printf("%d(%d, %d) ", tree->value, tree->hb, tree->hb2);
	inorder_traversal(tree->right);
}

void inorder_traversal_stack(node *tree) {
	node* stack[100] = {NULL};
	int i = 0;							//i denotes the next position in stack where to insert the element
	node *n = tree;
	stack[i++] = n;
	n = n->left;
	while(i > 0 || n) {
		if(n) {
			stack[i++] = n;
			n = n->left;
		}
		else {
			node *x = stack[--i];	
			printf("%d\t", x->value);
			n = x->right;
		}
	}
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

int update_heights(node *tree) {
	if(tree == NULL) return -1;
	
	int left_subtree_height = 1 + update_heights(tree->left);
	int right_subtree_height = 1 + update_heights(tree->right);
	int max = left_subtree_height;

	if(right_subtree_height > left_subtree_height) 
		max = right_subtree_height;

	tree->hb = max;
	return max;
}

void update_height_balance(node *tree) {
	if(tree == NULL) return;
	
	int left_subtree_height = find_height(tree->left);
	int right_subtree_height = find_height(tree->right);
	int disbalance = right_subtree_height - left_subtree_height;
	tree->hb2 = disbalance;

	update_height_balance(tree->left);
	update_height_balance(tree->right);
}

int find_height(node *n) {
	if(n == NULL) return -1;
	int left_subtree_height = find_height(n->left);
	int right_subtree_height = find_height(n->right);
	return 1 + (left_subtree_height > right_subtree_height ? left_subtree_height : right_subtree_height);
}
