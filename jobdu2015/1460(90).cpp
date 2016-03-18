#include <stdio.h>
int m, n;
bool buf[101][101];
bool mark[101][101];
int go[][2] = {
	0, 1,
	0, -1,
	1, 1,
	1, 0,
	1, -1,
	-1, 1,
	-1, 0,
	-1, -1
};

void DFS(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int newx = x + go[i][0];
		int newy = y + go[i][1];
		if (newx < 1 || newx > m || newy < 1 || newy > n) continue;
		if (!buf[newx][newy]) continue;
		if (mark[newx][newy]) continue;
		mark[newx][newy] = true;
		DFS(newx, newy);
	}
	return;
}

int main() {
	while (scanf("%d%d", &m, &n) != EOF && m != 0) {
		for (int i = 1; i <= m; i++) {
			char str[101];
			scanf("%s", str);
			for (int j = 1; j <= n; j++) {
				if (str[j - 1] == '*') {
					buf[i][j] = false;
				}
				else {
					buf[i][j] = true;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				mark[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (mark[i][j]) continue;
				if (!buf[i][j]) continue;
				DFS(i, j);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}