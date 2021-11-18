#include "tree_height.h"

int add_and_height(all *t) {
	int i;

	for (i = 0; i < t->N; i++) {
		add(rand(), t);
	}
	return height(t->data);
}

void loop(all *t) {
	int i;
	int sum;

	sum = 0;
	t->result = calloc(t->N, sizeof(int));
	for (i = 0; i < t->loop_time; i++) {
		init_pool(t);
		t->data = NULL;
		t->result[add_and_height(t)]++;
	}
	for (i = 0; i < t->N; i++) {
		sum += t->result[i] * i;
	}
	t->average = sum / t->loop_time;
}
