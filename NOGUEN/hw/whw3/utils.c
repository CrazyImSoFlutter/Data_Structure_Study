#include "whw3.h"

data *new_node(all *t) {
	data *r;

	if(t->top == NULL)
		return NULL;

	r = t->top;
	t->top = r->next;
	return r;
}

void add(char *word, all *t)
{
	int hh = hash(word);
	int i;
	data *r = t->hash_table[hh];
	data *p;

	p = new_node(t);
	if (p == NULL)
		return ;
	strncpy(p->data, word, 5);
	p->next = NULL;
	if (r == NULL)
		t->hash_table[hh] = p;
	else {
		t->hash_table[hh] = p;
		p->next = r;
	}
}

void print_collision(all *t) {
	int i;
	int c;
	int sum;
	data *r = NULL;
	sum = 0;

	for (i = 0; i < HASH_PRIME; i++) {
		c = 0;
		if (t->hash_table[i] == NULL)
			continue ;
		else {
			r = t->hash_table[i];
			while (r != NULL) {
				r = r->next;
				c++;
			}
			t->collision += (c - 1);
			sum += ((c + 1) * c) / 2;
		}
	}
	printf("collision: %d\n", t->collision);
	printf("key comparison: %d\n", sum);
}
