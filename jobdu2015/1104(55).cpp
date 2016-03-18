#include <stdio.h>
int main() {
	int n, a;
	while (scanf("%d%d", &n, &a) != EOF) {
		int k = 0;
		int t = 1;
		for (int i = 2; i <= n; i++) {
			t *= i;
			while (t % a == 0) {
				k++;
				t /= a;
			}
			t %= a;
		}
		printf("%d\n", k);
	}
	return 0;
}