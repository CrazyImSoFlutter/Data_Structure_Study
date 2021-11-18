#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "backend-bst.h"     

#define POOL_SIZE 10

// record structure
struct record {
  char name[3];
  char number[4];
  struct record * left;
  struct record * right;
};

void print_name(struct record *);
void print_number(struct record *);

// pool of memory
static struct record pool[POOL_SIZE]; // static because pool is strictly private
struct record * top=pool;  // a pointer variable for pool stack top.

// comparison function for records
int compare(char key[3], struct record *);

// data
struct record * data = NULL; // Initially NULL.


void init_pool() // Initialize the pool; Use right instead of next!!!
{
  int i;
  struct record *r=pool;
  struct record *s;

  pool[POOL_SIZE-1].right=NULL;  

  for(i=1;i<POOL_SIZE;i++) {  
    s=r++;
    s->right=r;
  }
}

// Get a node from the pool. Returns NULL if pool is empty. 
// When calling new_node(), make sure to check if it is NULL. 
struct record * new_node()  
{
  struct record *r;
  
  if(top==NULL) 
    return NULL;
    
  r=top;
  top=r->right;  // Again, right instead of next.
  return r;
}

// Push a node to the pool.
void free_node(struct record *r)
{
  r->right=top;  // Again, right instead of next.
  top=r;
}


/***********************
Address Book by binary search tree
**************************/

void search(char name[3])  
{
  struct record *r; // Pointer to record being compared.
                    //data or left/right field of a node.
  int result;
  r=data;

  while (r!=NULL) {
    if ((result=compare(name,r))<0)
      r=r->left;
    else if (result==0) {
      print_name(r);
      printf(" : ");
      print_number(r);
      printf(" was found.\n");
      return;
    }
    else // case >0
      r=r->right;
  }
  printf("Couldn't find the name.\n");
}


void add(char *name, char *number)
{
  struct record * new;
  struct record * current;
  struct record * parent;
  int i;

  parent = NULL;
  current = data;
  while (current)
  {
    parent = current;
	if (strncmp(name, parent->name, 3) <= 0)
      current = parent->left;
	else
	  current = parent->right;
  }
  new = new_node();
  if (!new)
  {
    printf("Can't add. The pool is empty!\n");
	return ;
  }
  else
  {
    for (i = 0; i < 3; i++)
	  new->name[i] = name[i];
	for (i = 0; i < 4; i++)
	  new->number[i] = number[i];
	new->left = NULL;
	new->right = NULL;
	if (parent)
	{
	  if (compare(name, parent) <= 0)
		parent->left = new;
	  else
		parent->right = new;
	}
	else
	  data = new;
  }
}


// The most complicated.
void delete(char name[3])
{
  struct record * parent;
  struct record * current;
  struct record * child;
  struct record * successor_parent;
  struct record * successor;
  int i;

  parent = NULL;
  current = data;
  while (current && compare(name, current))
  {
    parent = current;
	current = compare(name, current) < 0 ? parent->left : parent->right;
  }
  if (!current)
  {
    printf("Couldn't find the name.\n");
	return ;
  }
  if (!current->left && !current->right)
  {
	if (parent != NULL)
	{
	  if (parent->left == current)
	    parent->left = NULL;
	  else
		parent->right = NULL;
	}
	else
	  data = NULL;
  }
  else if (!current->left || !current->right)
  {
    child = (current->left) ? current->left : current->right;
	if (parent)
	{
	  if (parent->left == current)
	    parent->left = child;
	  else
		parent->right = child;
	}
	else
	  data = child;
  }
  else
  {
    successor_parent = current;
	successor = current->right;
	while (successor->left)
	{
	  successor_parent = successor;
	  successor = successor->left;
	}
	if (successor_parent->left == successor)
	  successor_parent->left = successor->right;
	else
	  successor_parent->right = successor->right;
	for (i = 0; i < 3; i++)
	  current->name[i] = successor->name[i];
	for (i = 0; i < 4; i++)
	  current->number[i] = successor->number[i];
	current = successor;
  }
  free_node(current);
  printf("The name was deleted.\n");  
}


/* Just a wrapper of strncmp().
Regard strncmp(a,b) as a-b.
Negative value if key is less than r.
​0​ if key and r are equal.
Positive value if key is greater than r. */
int compare(char key[3], struct record *r)
{
    return strncmp(key, r->name, 3);
}


void print_data(char * s, int n)
{
  int i;
  for (i=0; i<n; i++)
    putchar(s[i]);
}

void print_name(struct record *r)
{
  print_data(r->name, 3);
}

void print_number(struct record *r)
{
  print_data(r->number, 4);
}

void print_inorder(struct record *t)
{
  if (!t)
    return ;
  print_inorder(t->left);
  print_name(t);
  printf(" : ");
  print_number(t);
  printf("\n");
  print_inorder(t->right);
}

void print_list()  
{
  print_inorder(data);
}


// returns the height of the BST.
int height(struct record *t)
{
  int left;
  int right;
  if (!t)
	return -1;
  else
  {
	left = height(t->left);
	right = height(t->right);
	return 1 + (left > right ? left : right);
  }
}

void print_height()  
{
  printf("The Address Book BST's height is %d.\n", height(data));
}
