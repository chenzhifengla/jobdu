#include <stdio.h>
int main() {
	long long a, b;
	int m;
	while (scanf("%d", &m) != EOF && m != 0) {
		scanf("%lld%lld", &a, &b);
		long long sum = a + b;
		if (sum == 0) printf("0");
		int mradix[100];
		int index = 0;
		while (sum) {
			mradix[index++] = sum % m;
			sum /= m;
		}
		for (int i = index - 1; i >= 0; i--) {
			printf("%d", mradix[i]);
		}
		printf("\n");
	}
	return 0;
}