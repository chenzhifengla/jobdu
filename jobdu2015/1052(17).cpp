#include<stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int buf[201];
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		int x;
		scanf("%d", &x);
		int ans = -1;
		for (int i = 0; i < n; i++) {
			if (buf[i] == x) {
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}