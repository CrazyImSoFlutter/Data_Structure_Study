#include "whw3.h"

int main(int argc, char **argv) {
	char line[100];
	all t;

	init(&t);
	void *file = fopen(argv[1], "r");
	if (file == NULL)
		return 1;

	while (fgets(line, sizeof(line), file) != NULL ) {
		char tmp[5];

		if (line[0] == '*')
			continue ;
		strncpy(tmp, line, 5);
		add(tmp, &t);
	}
	
	print_collision(&t);
	fclose(file);

	return 0;
}
