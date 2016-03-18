#include <stdio.h>
int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF && m != 0 && n != 0) {
		int ans = 0;
		int min = m;
		int max = m;
		while (max <= n) {
			ans += max - min + 1;
			min *= 2;
			max = max * 2 + 1;
		}
		if (n >= min) {
			ans += n - min + 1;
		}
		printf("%d\n", ans);
	}
}