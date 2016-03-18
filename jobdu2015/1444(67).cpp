#include <stdio.h>
#define N 10000001
int buf[N];
int num[N];
int findRoot(int n) {
	if (buf[n] == -1) return n;
	else {
		buf[n] = findRoot(buf[n]);
		return buf[n];
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i < N; i++) {
			buf[i] = -1;
			num[i] = 1;
		}
		int a, b;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b) {
				buf[b] = a;
				num[a] += num[b];
			}
		}
		int max = 1;
		for (int i = 1; i < N; i++) {
			if (buf[i] == -1 && num[i] > max) {
				max = num[i];
			}
		}
		printf("%d\n", max);
	}
	return 0;
}