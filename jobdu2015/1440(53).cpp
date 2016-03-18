#include <stdio.h>
int main() {
	bool flag[50000] = { false };
	for (int i = 2; i < 25000; i++) {
		int bound = 50000 / i;
		for (int j = 2; j < bound; j++) {
			flag[i * j] = true;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		int num = 0;
		int half = n / 2;
		for (int i = 2; i <= half; i++) {
			if (!flag[i] && !flag[n - i]) num++;
		}
		printf("%d\n", num);
	}
	return 0;
}