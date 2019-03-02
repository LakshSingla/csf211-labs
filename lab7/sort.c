#include "sort.h"

#include <stdio.h>
#include <stdbool.h>

#include "structures.h"
#include "utils.h"

// Partition between indices start and end both inclusive
// Returns the index where last elem has been inserted
int partition(employee *arr, int start, int end) {
	unsigned long int el_id = arr[end].id;
	int x = start-1; 					// Location of elements less than or equal to the element to be partitioned
	int y = start;						// Location of elements before which we have checked
	while (y < end) {
		if(arr[y].id <= el_id) {
			++x;
			swap(arr + x, arr + y);
		}
		++y;
	}
	swap(arr + x + 1, arr + end);
	return x+1;
}

void quicksort(employee *arr, int len) {
	//quicksort_rec_internal(arr, 0, len-1, 1);
	quicksort_iter_internal(arr, 0, len-1, 1);
}

// Sorts between start to end, both inclusive
void quicksort_rec_internal(employee *arr, int start, int end, int S) { 
	if(end - start + 1 <= S) return;		//Base case
	
	int part = partition(arr, start, end);
	quicksort_rec_internal(arr, start, part-1, S);
	quicksort_rec_internal(arr, part+1, end, S);
	
}

void quicksort_iter_internal(employee *arr, int start, int end, int S) {
	push(start);
	push(end);
	while(!is_empty()) {
		int y = pop();				// Last element by which to partition
		int x = pop();				// First element by which to partition
		if(y - x + 1 <= S) continue;
		int part = partition(arr, x, y);
		push(x);
		push(part-1);
		push(part+1);
		push(y);
	}
}

void insertionsort(employee *arr, int len) {
	for(int i = 1; i < len; ++i) {
		int j = i;
		while(arr[j].id < arr[j-1].id && j > 0){
			swap(arr+j, arr + j - 1);
			--j;
		}
	}
}

void insightsort(employee *arr, int len, int S) {
	quicksort_iter_internal(arr, 0, len-1, S);
	insertionsort(arr, len);
}
