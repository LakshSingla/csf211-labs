#include "tree.h"

#include <stdlib.h>
#include <string.h>

#include "structures.h"

node create_new_tree() {
	node x = {
		.key = NULL,
		.first_child = NULL
		.right_sibling = NULL,
	};
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

	char *tokens[MAX_DELIMS] = {NULL};
	char *indiv_str;
	int x = 0;
	indiv_str = strtok(data);
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
	} while((indiv_str = strtok(NULL, '.')) != NULL);

	for(int i = MAX_DELIMS - 1; i >= 0; --i) {
		if(!tokens[i]) continue;
		
		char *prev = tree;
		char *head = tree;

		head = head->first_child;	
		while(head != NULL && strcmp(head) != 0) 
			head = head->right_sibling

		// Create space for the new node
		if(head == NULL) {
			node *new_node = (node *)malloc(sizeof(node));	
			new_node->first_child = NULL;
			new_node->right_sibling = NULL;
			new_node->key = tokens[i];
		}

		// Insert inside this only
	}
}


node *add_to_level(node *tree, int level, char *data) {
	node *first_child_of_level = tree;
	for (int i = 0; i < level; ++i) {
		first_child_of_level = first_child_of_level->first_child;
	}

}
