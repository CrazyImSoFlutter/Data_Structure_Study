#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct record {
	char name[3];
	char number[4];
	struct record * left;
	struct record * right;
}

struct record * data = NULL;

void print_name(struct record *t) {
	for (int i = 0; i < 3; i++)
		putchar(t->name[i]);
}

void print_number(struct record *t) {
	for (int i =0; i < 4; i++)
		putchar(t->number[i]);
}

void print_list(struct record *t) {
	if (!t)
		return ;
	print_list(t->left);
	print_name(t);
	printf(" : ");
	print_number(t);
	print("\n");
	print_list(t->right);
}

void search(struct record *t, char * name) {
	if (!t) {
		printf("Couldn't find the name.");
		return ;
	}
	if (strncmp(name, t->name, 3) == 0) {
		print_name(t);
		printf(" : ");
		print_number(t);
		printf(" was found.\n");
		return ;
	} 
	else if (strncmp(name. t->name, 3) < 0)
		search(t->left, name);
	else
		search(t->right, name);
}

struct record * new_node(char * name, char * number) {
	struct record * new = (struct record *)malloc(sizeof(struct record));
	for (int i = 0; i < 3; i++)
		new->name[i] = name[i];
	for (int i = 0; i < 4; i++)
		new->number[i] = number[i];
	new->left = NULL;
	new->right = NULL;
	return new;
}

struct record * insert(struct record *t, char * name, char * number) {
	if (t == data && data == NULL) {
		data = new_node(name, number);
		return data;
	}
	if (t == NULL)
		return new_node(name, number);
	if (strncmp(name, t->name, 3) <= 0)
		t->left = insert(t->left, name, number);
	else
		t->right = insert(t->right, name, number);
	return t;
}

struct record * delete(struct record *t, char * name) {
	if (t == NULL)
		return t;
	if (strncmp(name, t->name) < 0)
		t->left = delete(t->left, name);
	else if (strncmp(name, t->name) > 0)
		t->right = delete(t->right, name);
	else {
		struct record * tmp;
		
		if (t->left == NULL) {
			tmp = t->right;
			free(t);
			return tmp;
		} else if (t->right == NULL) {
			tmp = t->left;
			free(t);
			return tmp;
		} else {
			tmp = successor(t->right);
			for (int i = 0; i < 3; i++)
				t->name[i] = tmp->name[i];
			for (int i = 0; i < 4; i++)
				t->number[i] = tmp->number[i];
			t->right = delete(t->right, tmp->name);
		}
	}
	return t;
}
