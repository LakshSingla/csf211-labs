#include <stdlib.h>
#include <stdio.h>

#include "structures.h"
#include "bst.h"

int main() {
	node *tree = add_value(NULL, 2);
	add_value(tree, 2);
	add_value(tree, 10);
	add_value(tree, 7);
	add_value(tree, 12);
	add_value(tree, 1);
	add_value(tree, 3);
	add_value(tree, 16);
	add_value(tree, 15);
	add_value(tree, 21);
	add_value(tree, 22);
	inorder_traversal(tree);
	printf("\n");

	/*node *x = find_value(tree, 21);
	node *y = find_value(tree, 22);
	node *z = find_value(tree, 2);
	node *w = find_parent(tree, y);
	node *u = find_parent(tree, z);

	if(x->right == y) printf("a");
	if(z == NULL) printf("a");
	if(w == x) printf("c");
	if(u == NULL) printf("c");*/

	return 0;
}
