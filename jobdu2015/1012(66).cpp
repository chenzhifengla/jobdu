#include <stdio.h>

int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		int temp = findRoot(tree, tree[n]);
		tree[n] = temp;
		return temp;
	}
}

int main() {
	int n, m;
	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%d", &m);
		int tree[1001];
		for (int i = 1; i <= n; i++) {
			tree[i] = -1;
		}
		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &a, &b);
			a = findRoot(tree, a);
			b = findRoot(tree, b);
			if (a != b) tree[a] = b;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (tree[i] == -1) ans++;
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}