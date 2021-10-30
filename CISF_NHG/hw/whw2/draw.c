#include "tree_height.h"

void check(all *t) {
	int i;

	for (i = 0; i < t->N; i++) {
		if (t->result[i] != 0)
			t->max_draw = i;
		if (t->result[i] > t->max_value) {
			t->max_value = t->result[i];
			t->limit_flag = t->result[i] / 600;
			t->limit_flag++;
		}

	}
}

void my_mlx_pixel_put(all *t, int x, int y, int color)
{
    char    *dst;
 
    dst = t->addr + (y * t->line_length + x * (t->bpp / 8));
    *(unsigned int*)dst = color;
}

void draw_line(all *t, int n, int x, int y, int width, int color) {
	int i;
	int j;
	char *dst;

	for (i = 0; i < n; i++) {
		for (j = 0; j < width; j++) {
			my_mlx_pixel_put(t, 100 + x + j, y - i, color);
		}
	}
}

void draw(all *t) {
	int i;
	int width;
	char a[10];
	char b[20] = "index";
	char c[20] = "count";
	int color;
	int n;

	check(t);
	width = 800 / (t->max_draw - t->min_height);
	for (i = 0; i < t->max_draw - t->min_height; i++) {
		color = (i % 2) ? 0xEEEEEE : 0xDDDDDD;
		n = t->result[i + t->min_height] / t->limit_flag;
		if (t->result[i + t->min_height] != 0 && n == 0)
			n = 1;
		draw_line(t, n, i * width, 600, width, color);
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	for (i = 0; i < t->max_draw - t->min_height; i++) {
		itoa(i + t->min_height, a, 10);
		mlx_string_put(t->mlx, t->win, i * width + 100 + width / 2, 630, 0xDDDDDD, a);
	}
	for (i = 0; i < t->max_draw - t->min_height; i++) {
		itoa(t->result[i + t->min_height], a, 10);
		mlx_string_put(t->mlx, t->win, i * width + 100 + width / 2, 660, 0xDDDDDD, a);
	}
	mlx_string_put(t->mlx, t->win, 50, 600, 0xDDDDDD, b);
	mlx_string_put(t->mlx, t->win, 50, 630, 0xDDDDDD, c);
	t->draw_flag = 0;
}
