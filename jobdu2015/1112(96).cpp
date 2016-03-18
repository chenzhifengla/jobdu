#include <stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int k;
	while (scanf("%d", &k) != EOF) {
		int list[26];
		for (int i = 0; i < k; i++) {
			scanf("%d", &list[i]);
		}
		int dp[26];
		int tmax;
		for (int i = 0; i < k; i++) {
			tmax = 1;
			for (int j = 0; j < i; j++) {
				if (list[j] >= list[i]) {
					tmax = max(tmax, dp[j] + 1);
				}
			}
			dp[i] = tmax;
		}
		tmax = 1;
		for (int i = 0; i < k; i++) {
			tmax = max(tmax, dp[i]);
		}
		printf("%d\n", tmax);
	}
}