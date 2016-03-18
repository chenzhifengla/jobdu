#include <stdio.h>
#include <math.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		bool flag[20000] = { false };
		int bound = n / 2 + 1;
		for (int i = 2; i <= bound; i++) {
			if (flag[i]) continue;
			int bound2 = n / i + 1;
			for (int j = 2; j <= bound2; j++) {
				flag[i * j] = true;
			}
		}
		bool first = true;
		for (int i = 2; i < n; i++) {
			if (!flag[i] && i % 10 == 1) {
				if (first) {
					first = false;
					printf("%d", i);
				}
				else printf(" %d", i);
			}
		}
		if (first) printf("-1");
		printf("\n");
	}
	return 0;
}