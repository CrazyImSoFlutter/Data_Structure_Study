#include "tree_height.h"


int main() {
	all	t;
	char flag;

	t.top = t.pool;
	t.data = NULL;
	t.draw_flag = 1;
	t.max_value = 0;
	srand(time(NULL));
	init_pool(&t);
	printf("Choose a, b, or c for N.\n");
	printf("a. 50\n");
	printf("b. 100\n");
	printf("c. 500\n");
	flag = getchar();
	if (flag == 'a') {
		t.N = 50;
		t.min_height = (int)(log2(t.N));
	} else if (flag == 'b') {
		t.N = 100;
		t.min_height = (int)(log2(t.N));
	} else if (flag == 'c') {
		t.N = 500;
		t.min_height = (int)(log2(t.N));
	}
	printf("How many time will you loop?\n");
	scanf("%d", &t.loop_time);
	loop(&t);
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, 1080, 720, "tree_height");
	t.img = mlx_new_image(t.mlx, 1080, 720);
	t.addr = mlx_get_data_addr(t.img, &t.bpp, &t.line_length, &t.endian);
	draw(&t);
	mlx_loop(t.mlx);
}
