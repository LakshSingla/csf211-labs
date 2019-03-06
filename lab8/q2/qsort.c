#include "qsort.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern int size;

void printArray(int* studArray, int arrSize)
{
	// printing the array
	int i = 0;
	for(i=0;i<arrSize;i++)
	{
		printf("Arr[%d] is %d\n", i, studArray[i]);
	}
}

int* readData(char * fileName) {
	FILE *fp = fopen(fileName, "r");
	
	if(fp == NULL) {
		printf("Unable to open %s for reading. Exiting...\n", fileName);
		exit(0);
	}
	fscanf(fp, "%d", &size);
	int *arr = (int*)malloc(sizeof(int) * size);
	if(arr == NULL) {
		printf("Unable to reserve space for %d integers. Exiting...\n", size);
		exit(0);
	}
	int i = 0;
	while(fscanf(fp, " %*10s%d", arr+(i++)) != EOF);
	
	return arr;
}

int getGlobalSize() { 
	return size; 
}

KeyStruct extractKeys(int* Ls, int lsSize, int loKey, int hiKey) {
	int maxKeys = hiKey - loKey + 1;
	bool *present = (bool*)malloc(maxKeys * sizeof(bool));
	
	for(int i = 0; i < maxKeys; ++i) present[i] = false;
	
	int unique = 0;
	for(int i = 0; i < lsSize; ++i) {
		if(!present[Ls[i]-loKey]) {
			present[Ls[i]-loKey] = true;
			++unique;
		}
	}
	
	int *k = (int*)malloc(unique * sizeof(int));
	for(int i = 0, j = 0; i < maxKeys; ++i) {
		if(present[i]) {
			k[j++] = loKey + i; 
		}
	}
	free(present);
	KeyStruct x = (KeyStruct)malloc(sizeof(struct keyStruct));
	x->Keys = k;
	x->keysSize = unique;
	return x;
}
