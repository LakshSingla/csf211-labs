#include "multi_queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "structures.h"
#include "queue.h"

multi_queue create_multi_queue(int num) {
	multi_queue mq;
	mq.num = num;
	mq.q = (queue*)malloc(sizeof(queue) * num);
	for(int i = 0; i < num; ++i) {
		*(mq.q + i) = create_queue();
	}
	return mq;
}

void add_in_mq(multi_queue *mq, task t) {
	if(t.priority >= mq->num) {
		printf("Inadequate multiqueue\n");	
		return;
	}
	insert_in_queue((mq->q)+t.priority, t.task_id);
}

task del_next_mq(multi_queue *mq) {
	if(is_mq_empty(mq)) {
		printf("Underflow error, no tasks left\n");	
		task x = {
			.task_id = -1, 
			.priority = -1
		};
		return x;
	}
	int num = mq->num;
	queue *q = mq->q;
	for(int i = 0; i < num; ++i) {
		if(!is_queue_empty(q+i)) {
			long long int x = deque(q+i);
			task t = {
				.priority = i,
				.task_id = x
			};
			return t;
		}
	}
	//Unknown error case
	printf("Unknown error\n");
	task x = {
			.task_id = -1, 
			.priority = -1
		};
	return x;
}

task next_mq(multi_queue *mq) {
	if(is_mq_empty(mq)) {
		printf("No tasks left\n");	
		task x = {
			.task_id = -1, 
			.priority = -1
		};
		return x;
	}
	int num = mq->num;
	queue *q = mq->q;
	for(int i = 0; i < num; ++i) {
		if(!is_queue_empty(q+i)) {
			long long int x = peek(q+i);
			task t = {
				.priority = i,
				.task_id = x
			};
			return t;
		}
	}
	//Unknown error case
	printf("Unknown error\n");
	task x = {
			.task_id = -1, 
			.priority = -1
		};
	return x;
}

int size_mq(multi_queue *mq) {
	int num = mq->num;
	queue *q = mq->q;
	int len = 0;
	for(int i = 0; i < num; ++i) {
		len += len_queue(q+i);
	}
	return len;
}

int size_mq_by_priority(multi_queue *mq, int p) {
	queue *q = mq->q;
	if(p > mq->num) {
		printf("Inadequate multiqueue\n");	
		return -1;
	}
	return len_queue(q+p);
}

queue *get_q_from_mq(multi_queue *mq, int p) {
	if(p > mq->num) {
		printf("Inadequate multiqueue\n");	
		return NULL;
	}
	return (mq->q + p);
}

bool is_mq_empty(multi_queue *mq) {
	queue *q = mq->q;
	int num = mq->num;
	for(int i = 0; i < num; ++i) {
		if(!is_queue_empty(q+i)) return false;
	}
	return true;
}

void print_mq(multi_queue *mq) {
	for(int i = 0; i < mq->num; ++i) {
		printf("#%d\n", i);	
		print_queue(mq->q+i);
	}
}
