#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		int** buf = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++) {
			buf[i] = (int*)malloc(sizeof(int) * n);
			for (int j = 0; j < n; j++) {
				scanf("%d", &buf[i][j]);
			}
		}
		for (int i = 0; m - 1 - i >= i && n - 1 - i >= i; i++) {
			if (m - 1 - i == i && n - 1 - i == i) {
				printf("%d ", buf[i][i]);
				continue;
			}
			else if (m - 1 - i == i) {
				for (int j = i; j <= n - 1 - i; j++) {
					printf("%d ", buf[i][j]);
				}
				continue;
			}
			else if (n - 1 - i == i) {
				for (int j = i; j <= m - 1 - i; j++) {
					printf("%d ", buf[j][i]);
				}
				continue;
			}
			for (int j = i; j < n - 1 - i; j++) {
				printf("%d ", buf[i][j]);
			}
			for (int j = i; j < m - 1 - i; j++) {
				printf("%d ", buf[j][n - 1 - i]);
			}
			for (int j = n - 1 - i; j > i; j--) {
				printf("%d ", buf[m - 1 - i][j]);
			}
			for (int j = m - 1 - i; j > i; j--) {
				printf("%d ", buf[j][i]);
			}
		}
		printf("\n");
		
		for (int i = 0; i < m; i++) {
			free(buf[i]);
		}
		free(buf);
	}
	return 0;
}