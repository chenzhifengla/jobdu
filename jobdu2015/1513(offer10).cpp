#include <stdio.h>
int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			int num;
			scanf("%d", &num);
			int sum = 0;
			for (int i = 0; i < 32; i++) {
				if ((num & 1) == 1) {
					sum++;
				}
				num = num >> 1;
			}
			printf("%d\n", sum);
		}
	}
	return 0;
}