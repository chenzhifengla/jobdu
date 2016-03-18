#include <stdio.h>

int main() {
	bool flag[40001] = { false };
	for (int i = 2; i <= 20000; i++) {
		int bound = 40000 / i;
		for (int j = 2; j <= bound; j++) {
			flag[i * j] = true;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		int num = 0;
		int division = 2;
		while (n > 1) {
			if (n % division == 0) {
				num++;
				n /= division;
			}
			else {
				while (flag[++division]);
				if (division >= 40000) break;
			}
		}
		if (n > 1) num++;
		printf("%d\n", num);
	}
	return 0;
}