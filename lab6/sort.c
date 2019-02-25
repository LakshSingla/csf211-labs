#include "sort.h"

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"


void merge(student_record* ls1, int sz1, student_record* ls2, int sz2, student_record* ls) {
	int i, j, k;
	i =  j = k = 0;
	while ( !(i == sz1 && j == sz2) ) {
		if(i == sz1) {
			ls[k] = ls2[j];
			++j;
		}
		else if(j == sz2) {
			ls[k] = ls1[i];
			++i;	
		}
		else {
			if (ls1[i].cg <= ls2[j].cg) {
				ls[k] = ls1[i];
				++i;
			}
			else {
				ls[k] = ls2[j];
				++j;
			}
		}		
		++k; 
	}
}

void merge_sort(student_record* ls, int sz) {

	if(sz <= 1) return;
	
	int midpt = sz / 2;
	int sz1 = midpt;
	int sz2 = sz - midpt;
	student_record *ls1 = malloc(sizeof(student_record) * sz1);
	student_record *ls2 = malloc(sizeof(student_record) * sz2);
	for(int i = 0; i < sz1; ++i)
		ls1[i] = ls[i];
	for(int i = 0; i < sz2; ++i)	
		ls2[i] = ls[midpt+i];
		
	merge_sort(ls1, sz1);
	merge_sort(ls2, sz2);
	merge(ls1, sz1, ls2, sz2, ls);

	free(ls1);
	free(ls2);
	
}

/*void merge_sort_iterative(student_record *ls, int sz) {
	int block_size = 2;
	
	while(block_size / 2 <= sz) {
		int i = 0;
		while(i < sz) {
			student_record *ls_temp = malloc(sizeof(student_record) * block_size);
			int block1_start = i;
			int block2_start = i + block_size/2;
			
			//if(block2_start >= sz) break;
			int x = sz-block1_start;
			x = (block_size/2 < x ? block_size : x);
			int y = sz - block2_start;
			y = (block_size/2 < y ? block_size/2 : y);
			merge(ls+block1_start, block_size/2, ls+block2_start, y, ls_temp);
			
		
			for(int j = 0; j < block_size; ++j)
				ls[i+j] = ls_temp[j];
			
			i += block_size;
			free(ls_temp);
		}
		
		block_size *= 2;
	}
}*/

void merge_sort_iterative(student_record *ls, int sz) {
	int block_size = 1;
	while(block_size < sz) {
		int x = 0;
		int y = block_size;
		while(x < sz) {
			int len1 = (block_size < sz-x ? block_size : sz-x);
			int len2 = (block_size < sz-y ? block_size : sz-y);
			student_record *ls_temp = malloc(sizeof(student_record) * (block_size * 2));
			if(y < sz)  {
				merge(ls+x, len1, ls+y, len2, ls_temp);
				for(int j = 0; j < len1+len2; ++j) {
					ls[j+x] = ls_temp[j];
				}
			}
			free(ls_temp);
			x += block_size * 2;
			y += block_size * 2;
		}
		block_size *= 2;
	}
}
