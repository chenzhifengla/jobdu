#include <stdio.h>
int main() {
	int a, b;
	char n[100];
	while (scanf("%d%s%d", &a, n, &b) != EOF) {
		int radix10 = 0;
		for (int i = 0; n[i]; i++) {
			int num;
			if (n[i] >= '0' && n[i] <= '9') {
				num = n[i] - '0';
			}
			else if (n[i] >= 'a' && n[i] <= 'f') {
				num = n[i] - 'a' + 10;
			}
			else num = n[i] - 'A' + 10;
			radix10 *= a;
			radix10 += num;
		}
		if (radix10 == 0) printf("0");
		int radixb[100];
		int index = 0;
		while (radix10) {
			radixb[index++] = radix10 % b;
			radix10 /= b;
		}
		for (int i = index - 1; i >= 0; i--) {
			if (radixb[i] >= 10)
				printf("%c", radixb[i] - 10 + 'A');
			else printf("%d", radixb[i]);
		}
		printf("\n");
	}
	return 0;
}