#include <stdio.h>
int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		tree[n] = findRoot(tree, tree[n]);
		return tree[n];
	}
}
int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		for (int i = 0; i < t; i++) {
			int n, m;
			scanf("%d%d", &n, &m);
			int tree[1001];
			for (int j = 1; j <= n; j++) {
				tree[j] = -1;
			}
			for (int j = 0; j < m; j++) {
				int a, b;
				scanf("%d%d", &a, &b);
				a = findRoot(tree, a);
				b = findRoot(tree, b);
				if (a != b) {
					tree[b] = a;
				}
			}
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if (tree[j] == -1) ans++;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}