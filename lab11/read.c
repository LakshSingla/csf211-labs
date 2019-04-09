#include "read.h"

#include <stdlib.h>

#include "tree.h"

node *read_file(const char *filename) {
	FILE *fp = fopen(filename, "r");	
	if(fp == NULL) {
		printf("Unable to open %s for reading. Exiting...\n");	
		exit(0);
	}
	int choice;
	int fileend;
	//while((fileend=fscanf(fp, "%d")))
}
