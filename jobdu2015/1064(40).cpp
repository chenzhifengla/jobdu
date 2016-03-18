#include <stdio.h>
int main() {
	for (int i = 1000; i <= 1111; i++) {
		int j = i * 9;
		int k = i;
		int reverse = 0;
		while (k) {
			reverse *= 10;
			reverse += k % 10;
			k /= 10;
		}
		if (reverse == j) printf("%d\n", i);
	}
	return 0;
}