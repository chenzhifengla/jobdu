#include <stdio.h>
int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		tree[n] = findRoot(tree, tree[n]);
		return tree[n];
	}
}
int main() {
	int n, m;
	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%d", &m);
		int tree[1001];
		for (int i = 1; i <= 1000; i++) {
			tree[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			a = findRoot(tree, a);
			b = findRoot(tree, b);
			if (a != b) {
				tree[b] = a;
			}
		}
		int num = 0;
		for (int i = 1; i <= n; i++) {
			if (tree[i] == -1) num++;
		}
		if (num > 1) {
			printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}