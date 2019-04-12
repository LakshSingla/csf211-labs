#ifndef _HASH_H
#define _HASH_H

#include "structures.h"

int hash(char*, int, int);
long long int collision(char**, int, int , int);
hash_table* create_new_hash_table(int);
hash_table* insert_in_hash_table(hash_table*, char*, int, int, int);
hash_table* insert_all_in_hash_table(hash_table*, char**, int, int, int);
void print_frequency(hash_table*, int);
node *lookup(hash_table*, char*, int, int);
void lookup_all(hash_table*, char**, int , int , int );

#endif
