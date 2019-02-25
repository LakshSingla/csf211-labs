#ifndef SORT_H
#define SORT_H

#include "structures.h"
	
void merge(student_record*, int, student_record*, int, student_record*);
void merge_sort(student_record*, int);
void merge_sort_iterative(student_record* ls, int sz);

#endif
