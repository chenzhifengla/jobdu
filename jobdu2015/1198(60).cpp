#include <stdio.h>
#include <string.h>
int main() {
	char a[1001], b[1001];
	while (scanf("%s%s", a, b) != EOF) {
		int lena = strlen(a);
		int lenb = strlen(b);
		int lenc = lena > lenb ? lena : lenb;
		lena--;
		lenb--;
		char sum[1010];
		int current = 0;
		for (int i = lenc - 1; i >= 0; i--) {
			if (lena < 0) {
				sum[i] = b[lenb--] + current;
			}
			else if (lenb < 0) {
				sum[i] = a[lena--] + current;
			}
			else {
				sum[i] = a[lena--] + b[lenb--] + current - '0';
			}
			if (sum[i] > '9') {
				sum[i] -= 10;
				current = 1;
			}
			else current = 0;
		}
		if (current == 1) {
			sum[lenc + 1] = '\0';
			for (int i = lenc; i > 0; i--) {
				sum[i] = sum[i - 1];
			}
			sum[0] = '1';
		}
		else {
			sum[lenc] = '\0';
		}
		printf("%s\n", sum);
	}
	return 0;
}