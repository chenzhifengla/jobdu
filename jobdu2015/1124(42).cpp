#include <stdio.h>
int main() {
	char buf[100];
	while (scanf("%s", buf) != EOF) {
		if (buf[0] == '0') break;
		int n = 0;
		for (int i = 0; buf[i] != 0; i++)
			n += buf[i] - '0';
		int i = n % 9;
		if (i == 0) i = 9;
		printf("%d\n", i);
	}
	return 0;
}