#include<stdio.h>
#define diff 500000
int buf[1000001];
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < 1000001; i++) {
			buf[i] = 0;
		}
		int t;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			buf[t + diff] ++;
		}
		for (int i = 500000; i >= -500000; i--) {
			if (buf[i + diff]) {
				printf("%d", i);
				m--;
				if (m) {
					printf(" ");
				}
				else {
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}
