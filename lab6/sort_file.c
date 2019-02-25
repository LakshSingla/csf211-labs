#include "sort_file.h"

#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "structures.h"

void split_file_into_sorted(const char *fname) {
	const int max = MAX_ARR_SIZE;
	FILE *fp = fopen(fname, "r");	
	if(fp == NULL) {
		printf("%s not found \n", fname);	
		exit(0);
	}
	int file_no = 0;
	int records_read = 0;
	student_record rec;
	student_record *arr = malloc(sizeof(student_record) * max);

	int x;
	while(1) {
		if((x=fscanf(fp, "%[^,],%f\n", rec.name, &(rec.cg))) != EOF) {
			arr[records_read] = rec;	
			++records_read;
			if(records_read == max) {
				char file_no_str[10];
				sprintf(file_no_str, "data_%d", file_no);
				++file_no;
				merge_sort(arr, records_read);
				write_records_to_file(file_no_str, arr, records_read);	
				records_read = 0;
			}
		} else{
			if(!records_read) break;
			char file_no_str[10];
			sprintf(file_no_str, "data_%d", file_no);
			++file_no;
			merge_sort(arr, records_read);
			write_records_to_file(file_no_str, arr, records_read);	
			records_read = 0;
			break;
		}
	}
	free(arr);
	fclose(fp);
}

void write_records_to_file(const char *fname, student_record* arr, int sz) {
	FILE *fp = fopen(fname, "w");
	if(!fp) {
		printf("Unable to open %s for writing\n", fname);	
		exit(0);
	}
	for(int i = 0; i < sz; ++i) {
		fprintf(fp, "%s, %f\n", arr[i].name, arr[i].cg);
	}
	fclose(fp);
}
