#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mlx/mlx.h"

#define POOL_SIZE 500

struct num {
	int num;
	struct num *left;
	struct num *right;
}typedef num;

struct all {
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int bpp;
	int line_length;
	int endian;
	num pool[POOL_SIZE];
	num *top;
	num *data;
	int *result;
	int loop_time;
	int N;
	int min_height;
	int average;
	int max_draw;
	int draw_flag;
	int limit_flag;
	int max_value;
}typedef all;


/*about node*/
void		init_pool(all *t);
struct num	*new_node(all *t);

/*about tree*/
void		add(int n, all *t);
int			height(num *t);

/*about random loop*/
int			add_and_height(all *t);
void		loop(all *t);

/*about draw*/
void		check(all *t);
void		draw_line(all *t, int n, int x, int y, int width, int color);
void		draw(all *t);

/*about itoa*/
char		*itoa(int value, char *buffer, int radix);
