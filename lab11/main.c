#include <stdio.h>
#include <string.h>

#include "structures.h"
#include "tree.h"

int main() {
	node *tree = create_new_tree();
	add_hostname(tree, strdup("laksh.singla"), strdup("1.1.12.12"));
	add_hostname(tree, strdup("singla.singla"), strdup("2.1.12.12"));
	add_hostname(tree, strdup("laksh.singla.12"), strdup("3.1.12.12"));
	add_hostname(tree, strdup("s.singla"), strdup("23.123.41.1"));
	//prompt();
	find_hostname(tree, "laksh.singla.12");
	find_hostname(tree, "singla.singla");
	find_hostname(tree, "dne.dne");
	find_hostname(tree, "dne.singla.12");
	return 0;
}
