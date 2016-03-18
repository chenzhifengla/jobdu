#include<stdio.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMonth[13][2] = {
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
	int y, m, d;
	while (scanf("%d%d%d", &y, &m, &d) != EOF) {
		int day = 0;
		for (int i = 1; i <= m - 1; i++) {
			for (int j = 1; j <= dayOfMonth[i][ISYEAP(y)]; j++) {
				day++;
			}
		}
		for (int i = 1; i <= d; i++) {
			day++;
		}
		printf("%d\n", day);
	}
	return 0;
}