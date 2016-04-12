#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int maxNumer = 1;
		for (int i = 1; i <= n; i++) {
			maxNumer *= 10;
		}
		for (int i = 1; i < maxNumer; i++) {
			printf("%d\n", i);
		}
	}
	return 0;
}