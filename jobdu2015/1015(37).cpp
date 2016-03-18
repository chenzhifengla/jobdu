#include <stdio.h>
int main() {
	int a, b, k;
	while (scanf("%d%d%d", &a, &b, &k) != EOF && !(a == 0 && b == 0)) {
		int sum = a + b;
		bool flag = true;
		for (int i = 0; i < k; i++) {
			if (a % 10 != b % 10) {
				flag = false;
				break;
			}
			else {
				a /= 10;
				b /= 10;
			}
		}
		if (flag) {
			printf("-1\n");
		}
		else {
			printf("%d\n", sum);
		}
	}
	return 0;
}