#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

student_record *read_csv(const char * fname, int *length) {
	FILE* fp = fopen(fname, "r");
	if(fp == NULL) {
		printf("%s not found \n", fname);	
		exit(0);
	}
	int size = 10;
	int len = 0;
	student_record rec;
	student_record * arr = malloc(sizeof(student_record) * size);
	//scanf()
	while(fscanf(fp, "%[^,],%f", rec.name, &(rec.cg)) != EOF) {
		++len;
		if(len > size) {
			size *= 2;
			arr = realloc(arr, sizeof(student_record) * size);
		}
		arr[len-1] = rec;		
	}
	*length = len;
	fclose(fp);
	return arr;
}
