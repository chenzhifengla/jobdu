#include <stdio.h>
#include <algorithm>
struct Edge {
	int a, b, cost, flag;
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
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		int edgenum = n * (n - 1) / 2;
		for (int i = 0; i < edgenum; i++) {
			scanf("%d%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost, &edge[i].flag);
		}
		std::sort(edge, edge + edgenum);
		int tree[100];
		for (int i = 1; i <= n; i++) tree[i] = -1;
		for (int i = 0; i < edgenum; i++) {
			if (edge[i].flag == 1) {
				int a = findRoot(tree, edge[i].a);
				int b = findRoot(tree, edge[i].b);
				if (a != b) {
					tree[a] = b;
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < edgenum; i++) {
			if (edge[i].flag == 0) {
				int a = findRoot(tree, edge[i].a);
				int b = findRoot(tree, edge[i].b);
				if (a != b) {
					tree[a] = b;
					ans += edge[i].cost;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}