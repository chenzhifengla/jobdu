#include<stdio.h>
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		int f[201] = { 0 };
		int p[201] = { 0 };
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			f[i] = t;
			p[t]++;
		}
		for (int   i = 0; i < n; i++) {
			if (p[f[i]] > 1) {
				printf("%d\n", p[f[i]] - 1);
			}
			else {
				printf("BeiJu\n");
			}
		}
	}
	return 0;
}