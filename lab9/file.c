#include "file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char **parse_file(const char *filename, int *len) {
	int arr_size = 200;
	*len = 0;
	char **arr = (char **)malloc(sizeof(char*) * arr_size);
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("Unable to open %s for reading\n", filename);
		exit(0);
	}
	char x[100];
	while(fscanf(fp, "%s", x) != EOF) {
		char *ptr = x;
		bool is_valid = true;
		while(*ptr) {
			if(!((*ptr >= 'A' && *ptr <= 'Z') || (*ptr >= 'a' && *ptr <= 'z'))) {
				is_valid = false;
				break;
			}
			++ptr;
		}
		if(!is_valid) continue;

		++*len;
		if(*len > arr_size) {
			arr_size = (float) arr_size * 1.2;
			arr = realloc(arr, sizeof(char *) * arr_size);
			if(arr == NULL) {
				printf("Unable to reserve %d bytes reading\n", arr_size);
				exit(0);
			}
		}
		char *word = (char *)malloc(sizeof(char) * (strlen(x) + 1));
		strcpy(word, x);
		arr[*len-1] = word;
	}
	return arr;
}
