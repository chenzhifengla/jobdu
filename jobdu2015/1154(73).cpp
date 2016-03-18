#include <stdio.h>
#include <algorithm>
struct Edge {
	int a, b, cost;
	bool operator < (const Edge &c) const {
		return cost < c.cost;
	}
}edge[76];

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
		int edgenum = 0;
		for (int i = 0; i < n - 1; i++) {
			char start[2];
			int startnum;
			scanf("%s%d", start, &startnum);
			for (int j = 0; j < startnum; j++) {
				char end[2];
				int cost;
				scanf("%s%d", end, &cost);
				edge[edgenum].a = start[0] - 'A';
				edge[edgenum].b = end[0] - 'A';
				edge[edgenum].cost = cost;
				edgenum++;
			}
		}
		std::sort(edge, edge + edgenum);
		int tree[27];
		for (int i = 0; i < n; i++) tree[i] = -1;
		int ans = 0;
		for (int i = 0; i < edgenum; i++) {
			int a = findRoot(tree, edge[i].a);
			int b = findRoot(tree, edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].cost;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}