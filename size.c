#include <stdio.h>
void print1(int *ptr, int rows);

int main() {
	printf("\n[----- [Ȳ����] [2018032027] -----]\n\n");

	int **x;
	printf("sizeof(x) = %lu\n", sizeof(x));
	printf("sizeof(*x) = %lu\n", sizeof(*x));
	printf("sizeof(**x) = %lu\n", sizeof(**x));
	return 0;
}
