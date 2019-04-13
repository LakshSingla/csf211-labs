#include "avl.h"

#include <stdio.h>
#include <stdbool.h>

#include "structures.h"
#include "bst.h"

node* rotate(node *tree, node *parent, node *child) {
	node *grand_parent = find_parent(tree, parent);

	bool right_rotate = (parent->left == child);
	bool is_root = (grand_parent == NULL);
	bool left_area = false;
	left_area = (!is_root && grand_parent->left == parent);
	node *new_root = (is_root ? child : tree);

	if(right_rotate) {
		node *T1 = child->left,
				 *T2 = child->right,
				 *T3 = parent->right;
		
		parent->left = T2;
		child->right = parent;
		if(!is_root && left_area)
			grand_parent->left = child;	
		else if (!is_root && !left_area)
			grand_parent->right = child;	
	}

	else { node *T1 = parent->left,
				 *T2 = child->left,
				 *T3 = child->right;
		
		parent->right = T2;
		child->left = parent;
		if(!is_root && left_area)
			grand_parent->left = child;	
		else if (!is_root && !left_area)
			grand_parent->right = child;
	}

	update_heights(new_root);
	return new_root;
}
