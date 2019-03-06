#include "qsort.h"

extern int size;


int main(int argc, char* argv[])
{
	size = 0;
	
	//char * fileName = argv[1];
	//printf("%s\n",fileName);

	int* studentArray = readData("Input.txt");
	size = getGlobalSize();
	
	printArray(studentArray, size);
	
	KeyStruct x = extractKeys(studentArray, size, 10, 20);
	printArray(x->Keys, x->keysSize);

	//quickSortKnownKeyRange(studentArray,size, 10, 20);

	//printf("\nSorted output is:\n");

	//printArray(studentArray, size);
	
}
