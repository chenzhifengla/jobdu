#include<stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		int score[101] = { 0 };
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d", &t);
			score[t]++;
		}
		int s;
		scanf("%d", &s);
		printf("%d\n", score[s]);
	}
	return 0;
}