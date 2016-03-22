#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int list[2001];
int dp[1001][2001];
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
		}
		sort(list + 1, list + 1 + n);
		for (int i = 1; i <= n; i++) dp[0][i] = 0;
		for (int i = 1; i <= k; i++) {
			for (int j = 2 * i; j <= n; j++) {
				if (j > 2 * i)	dp[i][j] = dp[i][j - 1];
				else dp[i][j] = INT_MAX;
				int last = dp[i - 1][j - 2] + (list[j] - list[j - 1])*(list[j] - list[j - 1]);
				if (dp[i][j] > last) dp[i][j] = last;
			}
		}
		printf("%d\n", dp[k][n]);
	}
	return 0;
}