#include "reader.h"
#include "multi_queue.h"
#include "queue.h"
#include "structures.h"

int main(void) {
	/*queue q = create_queue();
	insert_in_queue(&q, 1992);
	len_queue(&q);
	insert_in_queue(&q, 12);
	len_queue(&q);
	insert_in_queue(&q, 12);
	len_queue(&q);
	insert_in_queue(&q, 42);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	insert_in_queue(&q, 1992);
	len_queue(&q);
	insert_in_queue(&q, 1992);
	len_queue(&q);
	deque(&q);
	len_queue(&q);
	insert_in_queue(&q, 1992);
	len_queue(&q);*/
	multi_queue mq = read_csv("input10.txt");
	print_mq(&mq);
	test_del(&mq, 12);
	return 0;
}
