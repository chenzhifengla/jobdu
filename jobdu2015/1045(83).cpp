#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= 100; i++) {
			for (int j = 0; j <= 100 - i; j++) {
				int k = 100 - i - j;
				if (15 * i + 9 * j + k <= n * 3) {
					printf("x=%d,y=%d,z=%d\n", i, j, k);
				}
			}
		}
	}
	return 0;
}