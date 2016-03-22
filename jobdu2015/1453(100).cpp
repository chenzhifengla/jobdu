#include <stdio.h>
#include <limits.h>
#define OFFSET 2000
int dp[101][4001];
int list[101];

int main() {
	int t;
	int cas = 0;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		bool havezero = false;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &list[++cnt]);
			if (list[cnt] == 0) {
				cnt--;
				havezero = true;
			}
		}
		n = cnt;
		for (int i = -2000; i <= 2000; i++) {
			dp[0][i + OFFSET] = -INT_MAX;
		}
		dp[0][0 + OFFSET] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = -2000; j <= 2000; j++) {
				int tmp1 = -INT_MAX, tmp2 = -INT_MAX;
				if (j + list[i] <= 2000 && dp[i - 1][j + list[i] + OFFSET] != -INT_MAX) {
					tmp1 = dp[i - 1][j + list[i] + OFFSET] + list[i];
				}
				if (j - list[i] >= -2000 && dp[i - 1][j - list[i] + OFFSET] != -INT_MAX) {
					tmp2 = dp[i - 1][j - list[i] + OFFSET] + list[i];
				}
				if (tmp1 < tmp2) {
					tmp1 = tmp2;
				}
				if (tmp1 < dp[i - 1][j + OFFSET]) {
					tmp1 = dp[i - 1][j + OFFSET];
				}
				dp[i][j + OFFSET] = tmp1;
			}
		}
		printf("Case %d: ", ++cas);
		if (dp[n][0 + OFFSET] == 0) {
			puts(havezero == true ? "0" : "-1");
		}
		else printf("%d\n", dp[n][0 + OFFSET] / 2);
	}
	return 0;
}
