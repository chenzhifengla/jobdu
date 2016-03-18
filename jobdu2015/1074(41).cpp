#include <stdio.h>
int main() {
	for (int i = 0; i < 256; i++) {
		int j = i * i;
		int reverse = 0;
		while (j) {
			reverse *= 10;
			reverse += j % 10;
			j /= 10;
		}
		if (reverse == i * i)
			printf("%d\n", i);
	}
	return 0;
}