#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 1) {
			printf("1\n");
		}
		else {
			long long a = 1, b = 2, c;
			for (int i = 3; i <= n; i++) {
				c = a + b;
				a = b;
				b = c;
			}
			printf("%lld\n", b);
		}
	}
	return 0;
}