#ifndef SORT_FILE_H
#define SORT_FILE_H

#define MAX_ARR_SIZE 256	
#include "structures.h"

void split_file_into_sorted(const char *);

void write_records_to_file(const char *, student_record* , int);

#endif
