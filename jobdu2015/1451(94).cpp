#include <stdio.h>
int main() {
	int n;
	long long buf[21];
	buf[1] = 0;
	buf[2] = 1;
	for (int i = 3; i <= 20; i++) {
		buf[i] = (i - 1) * (buf[i - 1] + buf[i - 2]);
	}
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", buf[n]);
	}
	return 0;
}