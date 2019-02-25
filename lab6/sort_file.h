#ifndef SORT_FILE_H
#define SORT_FILE_H

#define MAX_ARR_SIZE 256	
#include "structures.h"

void split_file_into_sorted(const char*, int*);
void merge_2_sorted_files(const char*, const char*, const char*);
void merge_n_sorted_files(const char*, const char*, int);
void write_records_to_file(const char *, student_record* , int);

#endif
