#include "sort_file.h"

#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "structures.h"

void split_file_into_sorted(const char *fname, int *num_files) {
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
	*num_files = file_no;
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

void merge_2_sorted_files(const char *in1, const char *in2, const char *out) {
	FILE *fin1 = fopen(in1, "r");
	FILE *fin2 = fopen(in2, "r");
	FILE *fout = fopen(out, "w");
	if(fin1 == NULL) {
		printf("Unable to open file %s for merging\n", in1);	
		exit(0);
	}
	else if(fin2 == NULL) {
		printf("Unable to open file %s for merging\n", in2);	
		exit(0);
	}
	else if(fout == NULL) {
		printf("Unable to open file %s for merging\n", out);	
		exit(0);
	}

	int x, y;
	student_record rec1, rec2;

	x = fscanf(fin1, "%[^,],%f\n", rec1.name, &(rec1.cg));
	y = fscanf(fin2, "%[^,],%f\n", rec2.name, &(rec2.cg));

	while(1) {
		if(x != EOF && y != EOF) {
			if(rec1.cg <= rec2.cg) {
				fprintf(fout, "%s, %f\n", rec1.name, rec1.cg);
				x = fscanf(fin1, "%[^,],%f\n", rec1.name, &(rec1.cg));
			} else {
				fprintf(fout, "%s, %f\n", rec2.name, rec2.cg);
				y = fscanf(fin2, "%[^,],%f\n", rec2.name, &(rec2.cg));
			}
		}else if(x == EOF && y != EOF) {
			fprintf(fout, "%s, %f\n", rec2.name, rec2.cg);
			y = fscanf(fin2, "%[^,],%f\n", rec2.name, &(rec2.cg));
		
		}else if(x !=EOF && y == EOF) {
			fprintf(fout, "%s, %f\n", rec1.name, rec1.cg);
			x = fscanf(fin1, "%[^,],%f\n", rec1.name, &(rec1.cg));
		}else {
			break;	
		}
	}

	fclose(fin1);
	fclose(fin2);
	fclose(fout);
}

void merge_n_sorted_files(const char *out, const char *pre, int n) {
	//Assumes files are from 0 to n-1 prepended with prefix `pre` and output is file out
	FILE *fout = fopen(out, "w");
	/*FILE *ftemp[] = {
		fopen("temp0", "r+"),
		fopen("temp1", "r+")
	};*/

	char *tempfiles[] = {
		"temp0", 
		"temp1"
	};

	FILE *c;	
	c = fopen(tempfiles[0], "w");
	fclose(c);
	c = fopen(tempfiles[1], "w");
	fclose(c);

	if(fout == NULL) {
		printf("n-Unable to open files for merging\n");
		exit(0);
	}

	for(int i = 0; i < n; ++i) {
		char filename[10];
		sprintf(filename, "%s%d", pre, i);
		int x = i % 2; 
		printf("%d\n", x);
		printf("%s-%s-%s\n",tempfiles[x],filename, tempfiles[!x]);
		merge_2_sorted_files(tempfiles[x], filename, tempfiles[!x]);
	}
	//fclose(ftemp[0]);
	//fclose(ftemp[1]);
	fclose(fout);
}
