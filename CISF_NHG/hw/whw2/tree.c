#include "tree_height.h"

void add(int n, all *t) {
	struct num *new;
	struct num *current;
	struct num *parent;
	int i;

	parent = NULL;
	current = t->data;
	while (current)
	{
		parent = current;
		if (n <= parent->num)
			current = parent->left;
		else
			current = parent->right;
	}
	new = new_node(t);
	if (!new) {
		return ;
	} else {
		new->num = n;
		new->left = NULL;
		new->right = NULL;
		if (parent) {
			if (n <= parent->num)
				parent->left = new;
			else
				parent->right = new;
		}
		else
			t->data = new;
	}
}

int height(num *t) {
	int left;
	int right;

	if (!t)
		return -1;
	else {
		left = height(t->left);
		right = height(t->right);
		return 1 + (left > right ? left : right);
	}
}
