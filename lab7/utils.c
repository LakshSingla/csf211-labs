#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "structures.h" 
#include "sort.h"

int stack[STACK_SIZE];
static long int stack_top = -1;			//Denotes the last filled element

void push(int el) {
	if(stack_top == STACK_SIZE) {
		printf("Stack overflow\n");
		exit(0);
	}
	
	stack[++stack_top] = el;
}

int pop() {
	if(stack_top == -1) {
		printf("Stack underflow\n");
		exit(0);
	}
	
	return stack[stack_top--];
}

bool is_empty() {
	return stack_top == -1;
}

employee *read_file(const char *filename, int *length) {
	FILE *fp = fopen(filename, "r");
	int sz = 10;
	int len = 0;
	employee *arr = (employee*)malloc(sizeof(employee) * sz);
	if(fp == NULL) {
		printf("Unable to open file \"%s\" for opening. Exiting...\n", filename);
		exit(0);
	}
	
	employee emp; 
	while(fscanf(fp, " %[^ ] %lu", emp.name, &(emp.id)) != EOF) {
		++len;
		if(len > sz) {
			sz *= 2;
			arr = realloc(arr, sizeof(employee) * sz);
		}
		arr[len-1] = emp;
	}
	*length = len;
	fclose(fp);
	return arr;
}

void swap(employee *first, employee *second) {
	employee temp = *first;
	*first = *second;
	*second = temp;
}

double measure_time(void (*f)(employee*, int), employee* arr, int len) {
	double elapsed_time;
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	f(arr, len);
	gettimeofday(&t2, NULL);
	elapsed_time = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsed_time += (t2.tv_usec - t1.tv_usec) / 1000.0;
	return elapsed_time;
}

void test_run(const char *filename, int max_len, double* itime, double* qtime) {
	employee *arr;
	int len;
	
	arr = read_file(filename, &len);
	len = (len < max_len ? len : max_len);
	*itime = measure_time(insertionsort, arr, len);
	free(arr);
	
	arr = read_file(filename, &len);
	len = (len < max_len ? len : max_len);
	*qtime = measure_time(quicksort, arr, len);
	free(arr);
	
}

int estimate_cutoff(const char *filename, double approx_range) {
	double itime, qtime;
	
	int min = 20, max = 1000;
	do {
		printf("*************************\n");
		int mid = (min + max) / 2;
		test_run(filename, mid, &itime, &qtime);
		printf("%d: I = %lf, Q = %lf\n", mid, itime, qtime);
		if(fabs(itime - qtime) < approx_range) return mid;
		else max = mid;
	} while(true);
}
