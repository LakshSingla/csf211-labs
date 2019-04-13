#include <stdio.h>

int main () {
	char buf[10];
	scanf("%c*", buf);
	printf("%c", *buf);
}
