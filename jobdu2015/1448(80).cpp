#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		int indegree[101];
		vector<int> edge[101];
		for (int i = 0; i < n; i++) {
			edge[i].clear();
			indegree[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			indegree[b]++;
		}
		queue<int> Q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				Q.push(i);
			}
		}
		int cnt = 0;
		while (!Q.empty()) {
			int a = Q.front();
			Q.pop();
			cnt++;
			for (int i = 0; i < edge[a].size(); i++) {
				int b = edge[a][i];
				indegree[b]--;
				if (indegree[b] == 0) {
					Q.push(b);
				}
			}
		}
		if (cnt == n) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}