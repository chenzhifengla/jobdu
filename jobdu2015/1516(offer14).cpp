#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int n;
	scanf("%d", &n);
	int* before = (int*)malloc(sizeof(int) * n);
	bool* flag = (bool*)malloc(sizeof(flag) * n);
	int* after = (int*)malloc(sizeof(int) * n);
	int oddNum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &before[i]);
		flag[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (before[i] % 2 == 1) {
			after[oddNum++] = before[i];
			flag[i] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!flag[i]) {
			after[oddNum++] = before[i];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		printf("%d ", after[i]);
	}
	printf("%d\n", after[n - 1]);
	return 0;
}