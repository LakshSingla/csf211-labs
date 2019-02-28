#ifndef UTILS_H
#define UTILS_H
#define STACK_SIZE 200000

#include <stdbool.h>
#include <sys/time.h>

#include "structures.h"

extern int stack[STACK_SIZE];

employee *read_file(const char *, int *);
void swap(employee *, employee *);
void push(int);
int pop();
bool is_empty();
double measure_time(void (*)(employee*, int), employee*, int);
void test_run(const char *, int, double*, double*);
int estimate_cutoff(const char*, double);

#endif
