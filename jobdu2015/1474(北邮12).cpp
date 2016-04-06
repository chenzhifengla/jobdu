#include <stdio.h>
int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		for (int i = 0; i < t; i++) {
			int n, k;
			scanf("%d%d", &n, &k);
			int buf[11][11], result[11][11];
			for (int j = 0; j < n; j++) {
				for (int x = 0; x < n; x++) {
					scanf("%d", &buf[j][x]);
					result[j][x] = buf[j][x];
				}
			}
			for (int j = 1; j < k; j++) {
				int tmp[11][11];
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < n; y++) {
						tmp[x][y] = 0;
						for (int z = 0; z < n; z++) {
							tmp[x][y] += buf[x][z] * result[z][y];
						}
					}
				}
				for (int x = 0; x < n; x++) {
					for (int y = 0; y < n; y++) {
						result[x][y] = tmp[x][y];
					}
				}
			}
			for (int j = 0; j < n; j++) {
				for (int m = 0; m < n - 1; m++) {
					printf("%d ", result[j][m]);
				}
				printf("%d\n", result[j][n - 1]);
			}
		}
	}
	return 0;
}