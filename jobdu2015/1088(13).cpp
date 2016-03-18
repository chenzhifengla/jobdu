#include<stdio.h>
int main() {
	int l, m;
	while (scanf("%d%d", &l, &m) != EOF) {
		int buf[10001];
		for (int i = 0; i <= l; i++) {
			buf[i] = 1;
		}
		for (int i = 0; i < m; i++) {
			int begin, end;
			scanf("%d%d", &begin, &end);
			for (int j = begin; j <= end; j++) {
				buf[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i <= l; i++) {
			if (buf[i] == 1) sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}