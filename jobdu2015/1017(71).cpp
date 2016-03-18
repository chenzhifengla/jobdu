#include <stdio.h>
#include <algorithm>
struct Edge {
	int a, b;
	int distance;
	bool operator < (const Edge &b) const {
		return distance < b.distance;
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
		int bound = n * (n - 1) / 2;
		for (int i = 1; i <= bound; i++) {
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].distance);
		}
		int tree[100];
		for (int i = 1; i <= n; i++) tree[i] = -1;
		std::sort(edge + 1, edge + bound + 1);
		int ans = 0;
		for (int i = 1; i <= bound; i++) {
			int a = findRoot(tree, edge[i].a);
			int b = findRoot(tree, edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].distance;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}