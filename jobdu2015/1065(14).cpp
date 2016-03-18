#include<stdio.h>
int main() {
	int h;
	while (scanf("%d", &h) != EOF) {
		for (int i = 0; i < h; i++) {
			for (int j = 1; j <= 2 * h - 2 - 2 * i; j++) {
				printf(" ");
			}
			for (int j = 1; j <= h + 2 * i; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}