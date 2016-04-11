#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		long long a = 0, b = 1, c;
		for (int i = 2; i <= n; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		printf("%lld\n", b);
	}
	return 0;
}