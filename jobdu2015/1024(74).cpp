#include <stdio.h>
#include <algorithm>
struct Edge {
	int a, b, cost;
	bool operator < (const Edge &c) const {
		return cost < c.cost;
	}
}edge[6000];

int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		tree[n] = findRoot(tree, tree[n]);
		return tree[n];
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF && n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
		}
		int tree[101];
		for (int i = 1; i <= m; i++) tree[i] = -1;
		std::sort(edge, edge + n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int a = findRoot(tree, edge[i].a);
			int b = findRoot(tree, edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		int rootnum = 0;
		for (int i = 1; i <= m; i++) {
			if (tree[i] == -1) rootnum++;
		}
		if (rootnum > 1) {
			printf("?\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}