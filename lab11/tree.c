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

node* add_data(node *tree, char *data) {
	/*char *new_data = (char *)malloc(strlen(data) + 1);
	node *new_node = (node *)malloc(sizeof(node) + 1);
	strcpy(new_data, data);
	new_node.key = new_data;*/

	/*Initialize delimiters*/
	//Assuming maximum number of '.' can be MAX_DELIMS, 1 more for storing string length
	

	/*int delims[MAX_DELIMS + 1]; 	
	for(int i = 0; i < 20; ++i) delims[i] = -1;
	int x = 0;
	for(int i = 0; i < strlen(data); ++i)
			if(data[i] = '.') 
				delims[x++] = i
	delims[x] = strlen(data);
	
	for(int i = 19; i >= 0; --i) {
		if(delims[i] == -1) continue;
		else {
			//Extract the part of the string between i and i-1	
			//Add to the xth level of the tree
		}
	}*/
	char delim[2] = ".";
	char *tokens[MAX_DELIMS] = {NULL};
	char *indiv_str;
	int x = 0;
	indiv_str = strtok(data, delim);
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
		//printf("%p\n", head);
		if(head == NULL) {
			new_node = (node*)malloc(sizeof(node));	
			new_node->first_child = NULL;
			new_node->right_sibling = NULL;
			new_node->key = tokens[i];
			//printf("here\n");
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
