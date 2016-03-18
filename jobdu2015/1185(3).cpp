#include<stdio.h>
#include<algorithm>
int main() {
	int n;
	int buf[1001];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		if (n == 1) printf("%d\n-1\n", buf[0]);
		else {
			std::sort(buf, buf + n);
			printf("%d\n%d", buf[n - 1], buf[0]);
			for (int i = 1; i < n - 1; i++) {
				printf(" %d", buf[i]);
			}
			printf("\n");
		}
	}
	return 0;
}