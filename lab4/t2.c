#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define L 10000
#define H 25000

int mem_used = 0;

void* myalloc(char *type, int n) {
	void *x;
	if(strcmp(type, "char") == 0){
		x = malloc(n * sizeof(char));
		mem_used += n * sizeof(char);
	}
	else if(strcmp(type, "int") == 0){
		x = malloc(n *sizeof(int));
		mem_used += n *sizeof(int);
	}
	return x;
}

void myfree(char *type, void *ptr, int n) {
	free(ptr);

	if(strcmp(type, "char") == 0){
		mem_used -= n * sizeof(char);
	}
	
	else if(strcmp(type, "int") == 0){
		mem_used -= n * sizeof(int);
	}
}

int main(void) {
	srand(time(0));
	//for(int i = 0; i < 100; ++i) {
	while(1){
		int random = L + rand() % (H - L);	
		int *x = (int*)myalloc("int", random);
		printf("%p - %p\n", x, x + (random-1));
		myfree("int", x, random);
	}
}
