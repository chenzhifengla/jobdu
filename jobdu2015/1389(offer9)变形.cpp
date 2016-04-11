#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			printf("1\n");
		}
		else {
			long long ans = 1;
			for (int i = 2; i <= n; i++) {
				ans *= 2;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}