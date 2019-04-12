#include <stdio.h>

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
	// for(int i = 0; i < len; ++i) printf("%s\n", xx[i]);
	int base_number, table_size;
	printf("Number of valid strings are: %d\n", len);
	best_hash_fn(arr, len, &base_number, &table_size);
	printf("BN: %d, TS: %d\n", base_number, table_size);
	//printf("%lld\n", collision(arr, len, 5413, 5000));
	//for(int i = 0; i < len; ++i) printf(arr[i]);
	//collision(arr, len, 1, 1);
	return 0;
}
