#include <stdio.h>

bool equal(double a, double b) {
	if (a - b < 0.0000001 && a - b > -0.0000001) {
		return true;
	}
	else return false;
}

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		while (t--) {
			double base;
			int exponent;
			scanf("%lf%d", &base, &exponent);
			if (equal(base, 0.0) && exponent <= 0) {
				printf("INF\n");
			}
			else {
				double result = 1;
				int absexponent = exponent > 0 ? exponent : (-exponent);
				for (int i = 1; i <= absexponent; i++) {
					result *= base;
				}
				if (exponent < 0) {
					result = 1 / result;
				}
				printf("%.2e", result);
				printf("f\n");
			}
		}
	}
	return 0;
}