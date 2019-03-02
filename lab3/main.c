#include "queue.h"
#include "structures.h"

int main(void) {
	queue q = create_queue();
	insert_in_queue(&q, 1992);
	print_queue(&q);
	insert_in_queue(&q, 12);
	print_queue(&q);
	insert_in_queue(&q, 12);
	print_queue(&q);
	insert_in_queue(&q, 42);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	insert_in_queue(&q, 1992);
	print_queue(&q);
	insert_in_queue(&q, 1992);
	print_queue(&q);
	deque(&q);
	print_queue(&q);
	insert_in_queue(&q, 1992);
	print_queue(&q);
	return 0;
}
