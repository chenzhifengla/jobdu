#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int num = z * 10 + y * 100 + x * 1000;
		int flag = 0;
		for (int i = 9; i > 0; i--) {
			for (int j = 9; j >= 0; j--) {
				int newnum = num + j + i * 10000;
				if (newnum % n == 0) {
					flag = 1;
					printf("%d %d %d\n", i, j, newnum / n);
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0)
			printf("0\n");
	}
	return 0;
}