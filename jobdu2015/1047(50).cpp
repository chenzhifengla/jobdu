#include <stdio.h>
#include <math.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		bool flag = true;
		if (n < 2) flag = false;
		else if (n > 2){
			int bound = (int)sqrt(n) + 1;
			for (int i = 2; i <= bound; i++) {
				if (n % i == 0) {
					flag = false;
					break;
				}
			}
		}
		if (flag) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}