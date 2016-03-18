#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int radix8[20];
		int index = 0;
		do {
			radix8[index++] = n % 8;
			n /= 8;
		} while (n);
		for (int i = index - 1; i >= 0; i--) {
			printf("%d", radix8[i]);
		}
		printf("\n");
	}
	return 0;
}