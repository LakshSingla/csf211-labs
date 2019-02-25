#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "reader.h"
#include "sort.h"

int main(void) {
	cards_info c; 
	//c = read_file("10");
	//c = read_file("100");
	//c = read_file("1000");
	//c = read_file("10000");
	//c = read_file("100000");
	c = read_file("1000000");
	//c = read_file("10000000");
	insertion_sort(c.start_value, 0, c.length);
	/*for(unsigned long long int i = 0; i < c.length; ++i) {
		printf("%llu\n", (c.start_value)[i].card_no);	
	}*/
	//printf("******************************************************************************************\n");
	//insertion_sort(c.start_value, c.length);
	//for(int i = 0; i < c.length; ++i) {
		//printf("%llu\n", (c.start_value)[i].card_no);	
	//}
	//fclose(fp);
	
}
