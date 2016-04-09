#include <stdio.h>
#include <stdlib.h>
#define INF 0x7fffffff
int max(int a, int b) {
	return a > b ? a : b;
}
struct E {
	int w;
	int v;
}list[100001];
int main() {
	int s, n;
	while (scanf("%d%d", &n, &s) != EOF) {
		int* dp = (int*)malloc(sizeof(int) * s);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &list[i].w, &list[i].v);
		}
		for (int i = 0; i <= s; i++) {
			dp[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = s; j >= list[i].w; j--) {
				
				if (j == s) {
					printf("dp[j] = %d\n", dp[j]);
					printf("dp[...] = %d+%d=%d\n", dp[j - list[i].w],
						list[i].v, dp[j - list[i].w] + list[i].v);
					if (dp[j] < dp[j - list[i].w] + list[i].v) {
						//dp[j] = dp[j - list[i].w] + list[i].v;
						printf("%d\n", i);
					}
				}
				dp[j] = max(dp[j], dp[j - list[i].w] + list[i].v);
			}
		}
		printf("%d\n", dp[s]);
	}
	return 0;
}