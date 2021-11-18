#include "tree_height.h"

void init_pool(all *t) {
	int i;
	struct num *r = t->pool;
	struct num *s;

	t->pool[POOL_SIZE - 1].right = NULL;
	for (i = 1; i < POOL_SIZE; i++) {
		s = r++;
		s->right = r;
	}
	t->top = t->pool;
}

num *new_node(all *t) {
	num *r;

	if (t->top == NULL)
		return NULL;

	r = t->top;
	t->top = r->right;
	return r;
}

