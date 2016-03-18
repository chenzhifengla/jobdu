#include <stdio.h>
int main() {
	for (int a = 1; a < 10; a++) {
		for (int b = 1; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				int sum = c * 2 + 10 * (b + c) + 100 * (a + b);
				if (sum == 532) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
	return 0;
}