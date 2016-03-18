#include <stdio.h>
#define M 200907
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int k;
			long long a, b, c, ans;
			scanf("%lld%lld%lld%d", &a, &b, &c, &k);
			if ((c - b) == (b - a)) {
				long long d = b - a;
				k = (k - 1) % M;
				d %= M;
				a %= M;
				ans = a + (d * k) % M;
			}
			else {
				long long q = b / a;
				ans = 1;
				k--;
				q %= M;
				while (k != 0) {
					if (k % 2 == 1) {
						ans *= q;
						ans %= M;
					}
					k /= 2;
					q *= q;
					q %= M;
				}
				a %= M;
				ans *= a;
			}
			ans %= M;
			printf("%d\n", ans);
		}
	}
	return 0;
}