#ifndef READER_H 
#define READER_H

#include "structures.h"

multi_queue read_csv(const char *filename);
void test_del(multi_queue *mq, int num);


#endif
