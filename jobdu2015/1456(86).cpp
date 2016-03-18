#include <stdio.h>
#include <queue>
using namespace std;
struct N {
	int x, y, z, t;
};
queue<N> Q;
int map[51][51][51];
int mark[51][51][51];
int go[][3] = {
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1
};
int BFS(int a, int b, int c) {
	while (!Q.empty()) {
		N now = Q.front();
		Q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if (nx < 0 || nx >= a || ny < 0 ||
				ny >= b || nz < 0 || nz >= c)
				continue;
			if (map[nx][ny][nz] == 1)
				continue;
			if (mark[nx][ny][nz])
				continue;
			N tmp;
			tmp.x = nx;
			tmp.y = ny;
			tmp.z = nz;
			tmp.t = now.t + 1;
			Q.push(tmp);
			mark[nx][ny][nz] = true;
			if (nx == (a - 1) && ny == (b - 1) && nz == (c - 1))
				return tmp.t;
		}
	}
	return -1;
}

int main() {
	int k;
	while (scanf("%d", &k) != EOF) {
		while (k--) {
			int a, b, c, t;
			scanf("%d%d%d%d", &a, &b, &c, &t);
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					for (int m = 0; m < c; m++) {
						scanf("%d", &map[i][j][m]);
						mark[i][j][m] = false;
					}
				}
			}
			while (!Q.empty()) Q.pop();
			mark[0][0][0] = true;
			N tmp;
			tmp.x = tmp.y = tmp.z = tmp.t = 0;
			Q.push(tmp);
			int time = BFS(a, b, c);
			if (time <= t) {
				printf("%d\n", time);
			}
			else {
				printf("-1\n");
			}
		}
	}
	return 0;
}