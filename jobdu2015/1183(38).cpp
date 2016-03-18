#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int pow = n * n;
		bool flag = true;
		while (n) {
			if (n % 10 != pow % 10) {
				flag = false;
				break;
			}
			else {
				n /= 10;
				pow /= 10;
			}
		}
		if (flag) printf("Yes!\n");
		else printf("No!\n");
	}
	return 0;
}