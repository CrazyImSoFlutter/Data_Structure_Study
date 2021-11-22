#include "whw3.h"

int hash(char key[5]) {
	int i;
	long long x;

    x = 0;
    for (i = 0; i < 4; i++) {
		x = x + key[i];
		x = x << 8;
	}
	x = x + key[4];
	return x % HASH_PRIME;
}
