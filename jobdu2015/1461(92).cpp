#include <stdio.h>
char map[8][8];
int n, m, t;
bool find;
int go[][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};

void DFS(int x, int y, int time) {
	for (int i = 0; i < 4; i++) {
		int newx = x + go[i][0];
		int newy = y + go[i][1];
		if (newx < 1 || newx > n || newy < 1 || newy > m) continue;
		if (map[newx][newy] == 'X') continue;
		if (map[newx][newy] == 'D') {
			if (time + 1 == t) {
				find = true;
				return;
			}
			else continue;
		}
		map[newx][newy] = 'X';
		DFS(newx, newy, time + 1);
		map[newx][newy] = '.';
		if (find) return;
	}
}

int main() {
	while (scanf("%d%d%d", &n, &m, &t) != EOF) {
		if (n == 0 && m == 0 && t == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%s", map[i] + 1);
		}
		find = false;
		int dx, dy;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 'D') {
					dx = i;
					dy = j;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == 'S' && (i + j) % 2 ==
					((dx + dy) % 2 + t % 2) % 2) {
					map[i][j] = 'X';
					DFS(i, j, 0);
				}
			}
		}
		if (find) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}