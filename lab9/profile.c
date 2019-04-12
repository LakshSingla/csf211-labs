#include "profile.h"

#include <stdio.h>
#include <limits.h>

#include "hash.h"

void best_hash_fn(char **arr, int len, int *base_number, int *table_size) {
	long long int min_collision = LLONG_MAX;
	*base_number = -1;
	*table_size = -1;
	//int possible_table_sizes[] = {5000, 50000, 500000};
	int possible_table_sizes[] = {21};
	/*int possible_base_numbers[][6] = {
		{5413, 6703, 8447, 5000011, 5000081, 5000101},
		{50551, 50707, 80929, 50000329, 50002861, 50003873},
		{755569, 765041, 768107, 500001529, 500002961, 500009927},
	};*/
	/*int possible_base_numbers[][6] = {
		{5413, 6703, 8447, 5000011, 5000081, 5000101}
	};*/
	int possible_base_numbers[][6] = {
		{54, 13, 7, 131, 97, 37}
	};
	for(int i = 0; i < 1; ++i) {
		for(int j = 0; j < 6; ++j) {
			int test_ts = possible_table_sizes[i];
			int test_bn = possible_base_numbers[i][j];
			printf("%d - %d, ", test_ts, test_bn);
			long long int collision_value = collision(arr, len, test_bn, test_ts) ;
			printf("%lld\n", collision_value);
			//long long int collision_value = 0;
			if(collision_value < min_collision) {
				*base_number = test_bn;
				*table_size = test_ts;
				min_collision = collision_value;
			}
		}
	}
}
