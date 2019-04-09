#include "tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "structures.h"

node *create_new_tree() {
	node *x = (node*)malloc(sizeof(node));
	x->key = NULL;
	x->ip = NULL;
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
			new_node->ip = NULL;
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
	head->ip = ip;
	return tree;
}

bool find_hostname(node *tree, char *hostname) {
	char *tokens[MAX_DELIMS] = {NULL};
	char delim[] = ".";
	char *hostname_copyable = strdup(hostname);
	char *token = strtok(hostname_copyable, delim);
	int i = 0;
	node *final_node;
	while(token != NULL) {
		tokens[i++] = strdup(token);
		token = strtok(NULL, delim);
	}
	i = MAX_DELIMS;
	while(!tokens[--i]);
	while(tree && i >= 0) {
		tree = tree->first_child;
		printf("%s, ", tokens[i]);
		while(tree && strcmp(tokens[i], tree->key) != 0)	tree = tree->right_sibling;
		--i;
	}
	if(tree)
		printf("%s\n", tree->ip);
	else 
		printf("Match not found\n");
	return true;
}

void print_data(const node *tree, int level) {
	while(tree) {
		if(tree->key) {
			printf("%d %s %s\n", level, tree->key, tree->ip);
		}
		print_data(tree->first_child, level+1);
		tree = tree->right_sibling;
	}	
}
