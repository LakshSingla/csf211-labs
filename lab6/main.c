#include <stdio.h>
#include <stdlib.h>

#include "sort.h"
#include "sort_file.h"
#include "structures.h"
#include "reader.h"


int main (void) { 
	/*student_record test[] = {
		{"", 1},
		{"", 2},
		{"", 1.5},
		{"", 7},
		{"", 9.5},
		{"", 1.2},
		{"", 3.0},
		{"", 4.12},
		{"", 3.3},
	};*/
	int len;
	student_record *ls = read_csv("1024.txt", &len);
	int num_files;

	//student_record rec;
	//scanf("%[^,],%f", rec.name, &(rec.cg));
	
	//printf("%s,%f", rec.name, (rec.cg));
	
	merge_sort_iterative(ls, len);
	//merge_sort_iterative(test, 9);
	
	
	for(int i = 0; i < len; ++i) printf("%s, %f\n", ls[i].name, ls[i].cg);
	//free(ls);
	//for(int i = 0; i < 9; ++i) printf("%d - %f\n",i, test[i].cg);
	//split_file_into_sorted("1024.txt", &num_files);
	//printf("%d\n", num_files);
	//merge_2_sorted_files("data_0", "data_1", "data_0-1");
	//merge_n_sorted_files("test", "data_", 4);
}
