#include <stdio.h>
int main() {
	int max;
	while (scanf("%d", &max) != EOF) {
		for (int i = 0; i < 9; i++) {
			int n;
			scanf("%d", &n);
			if (n > max) max = n;
		}
		printf("max=%d\n", max);
	}
	return 0;
}