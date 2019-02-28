#ifndef SORT_H
#define SORT_H

#include "structures.h"

int partition(employee *, int, int);
void quicksort(employee *, int );
void quicksort_rec_internal(employee *, int, int, int);
void quicksort_iter_internal(employee *, int, int, int);
void insertionsort(employee *, int);
void insightsort(employee *, int, int);

#endif
