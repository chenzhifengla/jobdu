#include <stdio.h>
int main() {
	int n;
	long long buf[21];
	buf[1] = 1;
	buf[2] = 2;
	for (int i = 3; i < 20; i++) {
		buf[i] = buf[i - 1] + buf[i - 2];
	}
	while (scanf("%d", &n) != EOF) {
		printf("%lld\n", buf[n]);
	}
	return 0;
}