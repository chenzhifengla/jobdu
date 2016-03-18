#include <stdio.h>
int main() {
	bool flag[40001] = { false };
	for (int i = 2; i <= 40000; i++) {
		if (flag[i]) continue;
		for (int j = i * i; j <= 40000; j += i) {
			flag[j] = true;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			int divisornum = 1;
			int thisdivisornum = 0;
			int division = 2;
			while (num > 1) {
				if (num % division == 0) {
					thisdivisornum++;
					num /= division;
				}
				else {
					if (thisdivisornum != 0) {
						divisornum *= (thisdivisornum + 1);
						thisdivisornum = 0;
					}
					while (flag[++division]);
					if (division >= 40000) break;
				}
			}
			if (thisdivisornum != 0) {
				divisornum *= (thisdivisornum + 1);
			}
			if (num > 1) divisornum *= 2;
			printf("%d\n", divisornum);
		}
	}
	return 0;
}