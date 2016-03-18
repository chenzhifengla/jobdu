#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		vector<int> edge[501];
		int indegree[501];
		bool mark[501];
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
			indegree[i] = 0;
			mark[i] = false;
		}
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			indegree[b]++;
		}
		for (int i = 1; i < n; i++) {
			int min = -1;
			for (int j = 1; j <= n; j++) {
				if (!mark[j] && indegree[j] == 0 && (min == -1 || j < min)) {
					min = j;
				}
			}
			mark[min] = true;
			for (int j = 0; j < edge[min].size(); j++) {
				int b = edge[min][j];
				indegree[b]--;
				//if (indegree[b] == 0) last = b;
			}
			printf("%d ", min);
		}
		for (int i = 1; i <= n; i++) {
			if (!mark[i]) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}