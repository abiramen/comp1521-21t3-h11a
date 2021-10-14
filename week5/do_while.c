#include <stdio.h>

int main(void) {
	int i = 12;

	do {
		i++;
		printf("%d", i);
		printf("\n");
	} while (i < 10);

	return 0;
}
