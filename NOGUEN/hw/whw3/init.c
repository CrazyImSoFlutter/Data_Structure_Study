#include "whw3.h"

void init_hash_table(all *t) {
	int i;
  
	for(i = 0; i < HASH_PRIME; i++)
		t->hash_table[i] = NULL;
}

void init_pool(all *t) {
	int i;
	data *r = t->pool;
	data *s;

	t->pool[POOL_SIZE-1].next = NULL;

	for (i = 1; i < POOL_SIZE; i++) {
		s = r++;
		s->next = r;
	}
}

void init(all *t) {
	t->top = t->pool;
	t->collision = 0;
	init_pool(t);
	init_hash_table(t);
}

