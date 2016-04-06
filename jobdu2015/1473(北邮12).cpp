#include <stdio.h>
int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		for (int i = 0; i < t; i++) {
			int n;
			scanf("%d", &n);
			if (n == 0) {
				printf("0");
			}
			else {
				int num[100];
				int index;
				for (index = 0; n != 0; index++) {
					num[index] = n % 2;
					n /= 2;
				}
				for (int i = index - 1; i >= 0; i--) {
					printf("%d", num[i]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}