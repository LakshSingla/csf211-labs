#include <stdio.h>
#include <string.h>

#include "structures.h"
#include "tree.h"

int main() {
	node *tree = create_new_tree();
	add_data(tree, strdup("laksh.singla"), strdup("1.1.12.12"));
	add_data(tree, strdup("singla.singla"), strdup("1.1.12.12"));
	add_data(tree, strdup("laksh.singla.12"), strdup("1.1.12.12"));
	add_data(tree, strdup("s.singla"), strdup("23.123.41.1"));
	return 0;
}
