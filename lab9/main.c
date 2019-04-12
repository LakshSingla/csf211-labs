#include <stdio.h>
#include <string.h>

#include "hash.h"
#include "file.h"
#include "profile.h"

int main() {

	/*printf("%d\n", hash("AB", 20, 5));
	const char *x[] = {
		"AB", "AB", "CD", "CD"
	};
	printf("%d\n", hash("CD", 20, 5));
	printf("%lld\n", collision(x, 3, 20, 5));*/

	int len;
	char **arr = parse_file("aliceinwonderland.txt", &len);
	int base_number = 71, table_size = 50;
	// for(int i = 0; i < len; ++i) printf("%s\n", xx[i]);
	//printf("Number of valid strings are: %d\n", len);
	//best_hash_fn(arr, len, &base_number, &table_size);
	//printf("BN: %d, TS: %d\n", base_number, table_size);
	//printf("%lld\n", collision(arr, len, 5413, 5000));
	//for(int i = 0; i < len; ++i) printf(arr[i]);
	//collision(arr, len, 1, 1);
	hash_table *x = create_new_hash_table(table_size);
	//insert_in_hash_table(x, strdup("ehllo"), 1, base_number, table_size);
	insert_all_in_hash_table(x, arr, len, base_number, table_size);
	//print_frequency(x, table_size);
	lookup_all(x, arr, len, base_number, table_size);
	//lookup(x, "sdlkafjl", base_number, table_size);
	printf("Insertion cost: %d\n", x->insertion_cost);
	printf("Querying cost: %d\n", x->querying_cost);
	return 0;
}
