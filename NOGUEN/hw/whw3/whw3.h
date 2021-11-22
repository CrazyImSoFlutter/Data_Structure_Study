#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_PRIME 12000
#define POOL_SIZE 6000

struct data {
	char data[5];
	struct data *next;
} typedef data;

struct all {
	data *hash_table[HASH_PRIME];
	data pool[POOL_SIZE];
	data *top;
	int collision;
} typedef all;

/*about hash.c*/
int		hash(char key[5]);

/*about init.c*/
void	init_hash_table(all *t);
void	init_pool(all *t);
void	init(all *t);

/*about utils.c*/
data	*new_node(all *t);
void	add(char *data, all *t);
void	print_collision(all *t);
