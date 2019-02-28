#include <stdio.h>
#include <stdlib.h>


#include "utils.h"
#include "structures.h"
#include "sort.h"

int main() {
	//int len;
  //employee *arr = read_file("100000", &len);
  //for(int i = 0; i < len; ++i)
  	//printf("%s %lu\n", arr[i].name, arr[i].id);
  
  //quicksort(arr, len);
  //insertionsort(arr, len);
  
  //insightsort(arr, len, 3);
  
  //printf("\n");
  //for(int i = 0; i < len; ++i)
  	//printf("%s %lu\n", arr[i].name, arr[i].id);
	double x, y;
	test_run("10000", 100, &x, &y);
  int cutoff = estimate_cutoff("100000", 0.0001);
  
  printf("#### CUTOFF: %d\n", cutoff);
  
  //free(arr);
  return 0;
}
