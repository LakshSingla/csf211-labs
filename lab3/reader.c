#include "reader.h"

#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "multi_queue.h"

multi_queue read_csv(const char *filename) {
	multi_queue mq;
	mq = create_multi_queue(11);
	FILE *fp = fopen(filename, "r");
	if(fp == NULL) {
		printf("Unable to read %s. Exiting...", filename);	
		exit(0);
	}
	task t;
	int x;
	while((x = fscanf(fp, "%lld,%d", &(t.task_id), &(t.priority))) != EOF) {
		add_in_mq(&mq, t);
	}
	fclose(fp);
	return mq;
}

void test_del(multi_queue *mq, int num) {
	while(num--) {
		task t = del_next_mq(mq);
		printf("%d, %lld\n", t.priority, t.task_id);
	}
}

