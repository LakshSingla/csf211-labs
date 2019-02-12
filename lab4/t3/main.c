#include "create_list.h"
#include "structures.h"
#include "test_cycle.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	srand(time(NULL));
	node *list1 = create_list(1000);
	node *list2 = create_list(1000);
	node *list3 = create_list(1000);
	node *list4 = create_list(1000);

	create_cycle(list1);
	create_cycle(list2);
	create_cycle(list3);
	create_cycle(list4);

	printf("CHECKING USING CYCLE1\n");
	printf("*****\n");
	cycle1(list1);
	cycle1(list2);
	cycle1(list3);
	cycle1(list4);

	printf("REVERSING USING CYCLE2\n");
	printf("*****\n");
	node *list1_n = cycle2(list1);
	node *list2_n = cycle2(list2);
	node *list3_n = cycle2(list3);
	node *list4_n = cycle2(list4);

	list1_n == list1 && printf("LIST1\n");
	list2_n == list2 && printf("LIST2\n");
	list3_n == list3 && printf("LIST3\n");
	list4_n == list4 && printf("LIST4\n");

	node *list1_n_n = cycle2(list1_n);

	FILE* fp = fopen("data.txt", "w");
	while(list1 != NULL) {
		fprintf(fp, "%d ---- %d\n", list1->data, list1_n_n->data);
		list1 = list1->next;	
		list1_n_n = list1_n_n->next;	
	}
	return 0;
}
