#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int* buf = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		int d;
		scanf("%d", &d);
		int left = (int)pow(2, d - 1) - 1;
		int right = (int)pow(2, d) - 1;
		if (n < left) {
			printf("EMPTY\n");
		}
		else if (n < right) {
			for (int i = left; i < n - 1; i++) {
				printf("%d ", buf[i]);
			}
			printf("%d\n", buf[n - 1]);
		}
		else {
			for (int i = left; i < right - 1; i++) {
				printf("%d ", buf[i]);
			}
			printf("%d\n", buf[right - 1]);
		}
		free(buf);
	}
	return 0;
}