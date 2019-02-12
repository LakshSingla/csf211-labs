#include <stdio.h>
void p();
void g();
void h();
void d();

int bits = 0;

void p(int i) {
	int pilani = 1;
	printf("%d****** -> %p\n", i, &pilani);
	p(i+1);
}
void g() {
	int goa = 2;
	printf("goa -> %p\n", &goa);
	h();
}
void h() {
	int hyderabad = 3;
	printf("hyderabad -> %p\n", &hyderabad);
	d();
}
void d() {
	int dubai = 4;
	printf("dubai -> %p\n", &dubai);
}

int main(void) {
	p(0);
	return 0;
}
