#include <stdlib.h>
#include <stdio.h>

#include "structures.h"
#include "bst.h"
#include "avl.h"
#include "stats.h"


int main() {
	node *tree = add_value(NULL, 2);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 2);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 10);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 7);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 12);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 1);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 3);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 16);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 15);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 21);
	inorder_traversal(tree);
	printf("\n");

	tree = add_value(tree, 22);
	inorder_traversal(tree);
	printf("\n");

	printf("**\n");
	inorder_traversal(tree);
	printf("\n");
	inorder_traversal_stack(tree);
	printf("\n");
	printf("**\n");

	/*node *a = find_value(tree, 2);
	node *b = find_value(tree, 1);

	tree = rotate(tree, a, b);
	inorder_traversal(tree);*/

	node *x = find_value(tree, 21);
	node *y = find_value(tree, 22);
	node *z = find_value(tree, 2);
	node *w = find_value(tree, 16);
	
	tree = delete_value(tree, x);
	inorder_traversal(tree);
	printf("\n");

	tree = delete_value(tree, y);
	inorder_traversal(tree);
	printf("\n");

	tree = delete_value(tree, z);
	inorder_traversal(tree);
	printf("\n");

	tree = delete_value(tree, w);
	inorder_traversal(tree);
	printf("\n");

	z = find_value(tree, 2);
	
	tree = delete_value(tree, z);
	inorder_traversal(tree);
	printf("\n");

	printf("**\n");
	inorder_traversal_stack(tree);


	/*inorder_traversal(tree);
	printf("\n");*/


	/*printf("%d - %d\n", 2, find_kth_value(tree, 2));
	printf("%d - %d\n", 3, find_kth_value(tree, 3));*/
	/*printf("%d - %d\n", 1, find_kth_value(tree, 1));
	printf("%d - %d\n", 7, find_kth_value(tree, 7));
	printf("%d - %d\n", 6, find_kth_value(tree, 6));*/

	/*find_in_range(tree, -1, 100);
	printf("\n");
	find_in_range(tree, 4, 7);
	printf("\n");
	find_in_range(tree, 1, 15);
	printf("\n");
	find_in_range(tree, 2, 3);
	printf("\n");*/

	//node *u = find_parent(tree, z);

	/*if(x->right == y) printf("a");
	if(z == NULL) printf("a");
	if(w == x) printf("c");
	if(u == NULL) printf("c");*/

	return 0;
}
