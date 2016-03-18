#include <stdio.h>
int ring[20];
bool mark[20];
int n;

bool judge(int num) {
	int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };
	for (int i = 0; i < 13; i++) {
		if (prime[i] == num) return true;
	}
	return false;
}

void DFS(int num) {
	if (num == n) {
		if (!judge(ring[n] + 1)) return;
		printf("1");
		for (int i = 2; i <= n; i++) {
			printf(" %d", ring[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (mark[i]) continue;
		if (!judge(ring[num] + i)) continue;
		mark[i] = true;
		ring[num + 1] = i;
		DFS(num + 1);
		mark[i] = false;
	}
}

int main() {
	int casenum = 1;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) mark[i] = false;
		printf("Case %d:\n", casenum++);
		ring[1] = 1;
		mark[1] = true;
		DFS(1);
		printf("\n");
	}
	return 0;
}