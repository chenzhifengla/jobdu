#include <stdio.h>
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (m == 0 && n == 0) break;
		int buf[101][101];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				buf[i][j] = buf[j][i] = -1;
			}
			buf[i][i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (buf[a][b] < 0 || buf[a][b] > c) {
				buf[a][b] = buf[b][a] = c;
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (buf[i][k] < 0 || buf[k][j] < 0) {
						continue;
					}
					if (buf[i][j] < 0 || (buf[i][k] + buf[k][j]) < buf[i][j]) {
						buf[i][j] = buf[i][k] + buf[k][j];
					}
				}
			}
		}
		printf("%d\n", buf[1][n]);
	}
	return 0;
}

#include <stdio.h>
#include <vector>
using namespace std;
struct E {
	int next;
	int distance;
};
vector<E> edge[101];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) edge[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			E tmp;
			tmp.distance = c;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		bool mark[101];		//表示是否已加入
		int dist[101];		//表示从起点到该点的距离
		for (int i = 1; i <= n; i++) {
			mark[i] = false;
			dist[i] = -1;
		}
		dist[1] = 0;
		mark[1] = true;
		int newP = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < edge[newP].size(); j++) {
				int next = edge[newP][j].next;
				int dis = edge[newP][j].distance;
				if (mark[next] == true) continue;
				if (dist[next] == -1 || dist[next] > dist[newP] + dis) {
					dist[next] = dist[newP] + dis;
				}
			}
			int min = -1;
			for (int j = 1; j <= n; j++) {
				if (mark[j] == true) continue;
				if (dist[j] == -1) continue;
				if (min < 0 || dist[j] < min) {
					min = dist[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		printf("%d\n", dist[n]);
	}
	return 0;
}