#include <stdio.h>
int buf[1001][1001];
int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		int t;
		scanf("%d", &t);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &buf[i][j]);
			}
		}
		int x = m - 1, y = 0;
		bool find = true;
		while (1) {
			if (t == buf[x][y]) {
				break;
			}
			else if (t > buf[x][y]) {
				y++;
				if (y >= n) {
					find = false;
					break;
				}
			}
			else {
				x--;
				if (x < 0) {
					find = false;
					break;
				}
			}
		}
		if (find) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}