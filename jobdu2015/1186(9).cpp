#include<stdio.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMonth [13][2]= {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};
int main() {
	int y, n;
	while (scanf("%d%d", &y, &n) != EOF) {
		int m = 1, d = 0;
		int day = 0;
		for (int day = 0; day < n; day++) {
			d++;
			if (d > dayOfMonth[m][ISYEAP(y)]) {
				m++;
				d = 1;
			}
		}
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0;
}