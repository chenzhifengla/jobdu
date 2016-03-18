#include <stdio.h>
int main() {
	char a[20], b[20];
	while (scanf("%s%s", a, b) != EOF) {
		int sum = 0;
		for (char* p = a; *p; p++) {
			for (char* q = b; *q; q++) {
				sum += (*p - '0') * (*q - '0');
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}