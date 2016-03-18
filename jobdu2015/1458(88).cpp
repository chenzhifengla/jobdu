#include <stdio.h>

long long F(int n) {
	if (n == 1) return 2;
	else return 3 * F(n - 1) + 2;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", F(n));
	}
	return 0;
}