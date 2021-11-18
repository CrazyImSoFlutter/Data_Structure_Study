#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend.h"
#include "memory.h"

void print_name(struct record *);
void print_number(struct record *);
void print_data(char *, int);

// data
struct record * data = NULL; // Initially NULL.

void init()
{
  init_pool();
}

void add(char *name, char *number)
{
  struct record *new;
  int i;
  
  new = new_node();
  if (new == NULL)
  {
    printf("Can't add.  The address book is full!\n");
    return ;
  }
  for (i = 0; i < 3; i++)
    new->name[i] = name[i];
  for (i = 0; i < 4; i++)
	new->number[i] = number[i];
  if (data == NULL)
  {
    new->next = NULL;
	data = new;
  }
  else
  {
    new->next = data;
	data = new;
  }
}


/* Just a wrapper of strncmp(), except for the case r is NULL.
Regard strncmp(a,b) as a-b, that is,
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
int compare(char key[3], struct record *r)
{
  if (r==NULL)
    return -1;
  else
    return strncmp(key, r->name, 3);
}


void search(char name[3])
{
  struct record *r=data;
  int result;

  while(r!=NULL && (result=compare(name,r))!=0)
    r=r->next;
  if(r==NULL)
    printf("Couldn't find the name.\n");
  else {
    print_name(r);
    printf(" : ");
    print_number(r);
    printf(" was found.\n");
  }
}


void delete(char name[3])
{
  struct record * first;
  struct record * before;

  first = data;
  before = NULL;
  while (first)
  {
	if (compare(name, first) == 0)
	{
	  if (first == data)
	  {
		data = first->next;
		free_node(first);
		printf("The name was deleted.\n");
		return ;
	  }
	  else
	  {
		before->next = first->next;
        free_node(first);
		printf("The name was deleted.\n");
		return ;
	  }
	}
	before = first;
	first = first->next;
  }
  printf("Couldn't find the name.\n");
}


// Prints ith name.
void print_name(struct record *r)
{
  print_data(r->name, 3);
}

// Prints ith number.
void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_list()
{
  struct record * first;

  first = data;
  while (first)
  {
    print_name(first);
	printf(" : ");
	print_number(first);
	printf("\n");
	first = first->next;	
  }
}
