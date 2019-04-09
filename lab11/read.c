#include "read.h"

#include <stdio.h>
#include <string.h>

#include "structures.h"
#include "tree.h"

void prompt() {
	int choice;
	node *tree = create_new_tree();
	do {
		printf("Enter a choice (1, 2, -1): ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				int number;
				char hostname[200];
				char ip[30];
				scanf("%d", &number);
				while(number--) {
					scanf(" %s %s", hostname, ip);	
					add_hostname(tree, strdup(hostname), strdup(ip));
				}
				break;
			}
			case 2: {
				break;	
			}
			case -1: {
				break;				
			}

			default:
				printf("Please enter a valid input\n");
				break;
		}
	} while(choice != -1);
	print_data(tree, 0);
}
