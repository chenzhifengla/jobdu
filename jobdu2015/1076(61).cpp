#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		char buf[10000] = { '1' };
		int index = 1;
		for (int i = 2; i <= n; i++) {
			int current = 0;
			for (int j = 0; j < index; j++) {
				int num = i * (buf[j] - '0') + current;
				buf[j] = num % 10 + '0';
				current = num / 10;
			}
			while (current > 0) {
				buf[index++] = current % 10 + '0';
				current /= 10;
			}
		}
		for (int i = index - 1; i >= 0; i--) {
			printf("%c", buf[i]);
		}
		printf("\n");
	}
	return 0;
}