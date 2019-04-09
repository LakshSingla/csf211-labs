#include <stdio.h>
#include <string.h>

#include "structures.h"
#include "tree.h"

int main() {
	node *tree = create_new_tree();
	add_data(tree, strdup("laksh.singla"));
	add_data(tree, strdup("singla.singla"));
	add_data(tree, strdup("laksh.singla.12"));
	add_data(tree, strdup("s.singla"));
	//print_data(tree, 0);
	return 0;
}
