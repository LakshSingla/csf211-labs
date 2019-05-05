#include "stats.h"

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

int find_kth_value(node* tree, int k) {
	static int rank = 0;	
	if(tree == NULL) return -1;
	int x = find_kth_value(tree->left, k);
	if(x + 1) return x;
	++rank;	
	printf("%d(%d) ", tree->value, rank);
	if(rank == k) return tree->value;
	x = find_kth_value(tree->right, k);
	if(x + 1) return x;
	return -1;
}

node *find_kth_value_internal(node *tree, node *n, int rank) {
	if(n) return n;

	find_kth_value_internal(tree, n, rank);
		
}

void find_in_range(node *tree, int r1, int r2) {
	if(!tree) return;
	if(tree->value > r2) return find_in_range(tree->left, r1, r2);
	else if(tree->value < r1) return find_in_range(tree->right, r1, r2);
	else {
		printf("%d ", tree->value);	
		find_in_range(tree->left, r1, tree->value);
		find_in_range(tree->right, tree->value, r2);
	}
}


