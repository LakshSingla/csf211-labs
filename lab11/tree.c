#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structures.h"

node *create_new_tree() {
	node *x = (node*)malloc(sizeof(node));
	x->key = NULL;
	x->first_child = NULL;
	x->right_sibling = NULL;
	return x;
}

//It is assumed that add_hostname has full control of the 
//hostname and ip memory and is to be released by the caller
//function
node* add_hostname(node *tree, char *hostname, char *ip) {
	char delim[2] = ".";
	char *tokens[MAX_DELIMS] = {NULL};
	char *indiv_str;
	int x = 0;
	indiv_str = strtok(hostname, delim);
	do {
		if(indiv_str != NULL) {		//For the first string
			char *duplicate_str = strdup(indiv_str);
			if(!duplicate_str) {
				//Error insufficient memory available	
				printf("Insufficient memory available. Exiting...\n");
				exit(0);
			}
			tokens[x++] = duplicate_str;
		}	
	} while((indiv_str = strtok(NULL, ".")) != NULL);

	node *prev = tree;
	node *head = tree;
	for(int i = MAX_DELIMS - 1; i >= 0; --i) {
		if(!tokens[i]) continue;

		node *prev_sibling = NULL;
		head = head->first_child;

		while(head != NULL && strcmp(head->key, tokens[i]) != 0) {
			prev_sibling = head;
			head = head->right_sibling;
		}

		// Create space for the new node
		node *new_node;
		if(head == NULL) {
			new_node = (node*)malloc(sizeof(node));	
			new_node->first_child = NULL;
			new_node->right_sibling = NULL;
			new_node->key = tokens[i];
		}
		else {
			new_node = head;	
		}
		// Insert inside this only
		if(prev->first_child == NULL) prev->first_child = new_node;
		if(prev_sibling && prev_sibling->right_sibling == NULL) prev_sibling->right_sibling = new_node;
		head = new_node;
		prev = head;
	}
	return tree;
}

/*node *add_to_level(node *tree, int level, char *data) {
	node *first_child_of_level = tree;
	for (int i = 0; i < level; ++i) {
		first_child_of_level = first_child_of_level->first_child;
	}
}*/

void print_data(const node *tree, int level) {
	while(tree) {
		if(tree->key) {
			printf("%d %s\n", level, tree->key);
		}
		print_data(tree->first_child, level+1);
		tree = tree->right_sibling;
	}	
}
