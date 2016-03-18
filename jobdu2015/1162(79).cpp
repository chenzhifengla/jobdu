#include <stdio.h>
#include <vector>
using namespace std;
struct E {
	int next;
	int len;
};
vector<E> edge[601];
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		for (int i = 1; i <= n; i++) edge[i].clear();
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b, t;
			scanf("%d%d%d", &a, &b, &t);
			E tmp;
			tmp.len = t;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
		}
		bool camp[601];	//true表示阵营2，flase表示阵营1
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			camp[i] = ((num == 1) ? false : true);
		}
		for (int i = 1; i <= n; i++) {
			if (camp[i]) {
				for (int j = 0; j < edge[i].size(); j++) {
					if (!camp[edge[i][j].next]) {
						//来自阵营2，去向阵营1
						edge[i].erase(edge[i].begin() + j);
						j--;
					}
				}
			}
		}
		int dis[601];
		bool mark[601];
		for (int i = 1; i <= n; i++) {
			dis[i] = -1;
			mark[i] = false;
		}
		dis[1] = 0;
		mark[1] = true;
		int newP = 1;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < edge[newP].size(); j++) {
				int t = edge[newP][j].next;
				int c = edge[newP][j].len;
				if (mark[t]) continue;
				if (dis[t] == -1 || dis[t] > dis[newP] + c)
					dis[t] = dis[newP] + c;
			}
			int min = -1;
			for (int j = 1; j <= n; j++) {
				if (mark[j]) continue;
				if (dis[j] == -1) continue;
				if (min == -1 || dis[j] < min) {
					min = dis[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		printf("%d\n", dis[2]);
	}
	return 0;
}