#include <stdio.h>
#include <vector>
using namespace std;
struct E {
	int next, length, cost; 
};
vector<E> v[1001];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			E temp;
			temp.length = c;
			temp.cost = d;
			temp.next = b;
			v[a].push_back(temp);
			temp.next = a;
			v[b].push_back(temp);
		}
		bool mark[1001];	//表示是否已加入集合
		int len[1001];		//表示起点到某点的距离
		int co[1001];		//表示起点到某点的花费
		for (int i = 1; i <= n; i++) {
			mark[i] = false;
			len[i] = -1;
			co[i] = -1;
		}
		int s, t;
		scanf("%d%d", &s, &t);
		int newP = s;
		mark[s] = true;
		len[s] = 0;
		co[s] = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < v[newP].size(); j++) {
				int t = v[newP][j].next;
				int length = v[newP][j].length;
				int cost = v[newP][j].cost;
				if (mark[t]) continue;
				if (len[t] == -1 || len[t] > len[newP] + length ||
					(len[t] == len[newP] + length && co[t] > co[newP] + cost)) {
					len[t] = len[newP] + length;
					co[t] = co[newP] + cost;
				}
			}
			int minlen = -1;
			int mincost = -1;
			for (int j = 1; j <= n; j++) {
				if (mark[j]) continue;
				if (len[j] < 0) continue;
				if (minlen < 0 || minlen > len[j] ||
					(minlen == len[j] && mincost < co[j])) {
					minlen = len[j];
					mincost = co[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		printf("%d %d\n", len[t], co[t]);
	}
	return 0;
}