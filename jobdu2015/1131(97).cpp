#include <stdio.h>
int max(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int list[101];
		for (int i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}
		int dpleft[101], dpright[101];
		int maxleft, maxright;
		for (int i = 0; i < n; i++) {
			maxleft = 1;
			for (int j = 0; j < i; j++) {
				if (list[j] < list[i]) {
					maxleft = max(maxleft, dpleft[j] + 1);
				}
			}
			dpleft[i] = maxleft;
		}
		for (int i = n - 1; i >= 0; i--) {
			maxright = 1;
			for (int j = n - 1; j > i; j--) {
				if (list[j] < list[i]) {
					maxright = max(maxright, dpright[j] + 1);
				}
			}
			dpright[i] = maxright;
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = max(sum, dpleft[i] + dpright[i]);
		}
		sum--;
		printf("%d\n", n - sum);
	}
	return 0;
}