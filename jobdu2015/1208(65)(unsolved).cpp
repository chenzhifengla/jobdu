#include <stdio.h>

int multi(char radix[], int size, int m, int n) {
	int current = 0;
	for (int i = 0; i < size; i++) {
		int num = (radix[i] - '0') * m + current;
		radix[i] = num % n + '0';
		current = num / n;
	}
	while (current > 0) {
		radix[size++] = current % n + '0';
		current /= n;
	}
	return size;
}

int plus(char radix[], int size, int current, int n) {
	int index = 0;
	while (current > 0) {
		int num = radix[index] - '0' + current;
		radix[index++] = num % n + '0';
		current = num / n;
	}
	return size > index ? size : index;
}

int main() {
	char radix10[10000];
	while (scanf("%s", radix10) != EOF) {
		char radix2[10000];
		for (int i = 0; i < 10000; i++) radix2[i] = '0';
		int size2 = 0;
		for (int i = 0; radix10[i]; i++) {
			size2 = multi(radix2, size2, 10, 2);
			size2 = plus(radix2, size2, radix10[i] - '0', 2);
		}
		/*
		int inter = size2 / 2;
		int t;
		for (int i = 0; i < inter; i++) {
			t = radix2[i];
			radix2[i] = radix2[size2 - 1 - i];
			radix2[size2 - 1 - i] = t;
		}
		*/
		for (int i = 0; i < 10000; i++) radix10[i] = '0';
		int size10 = 0;
		for (int i = 0; i < size2; i++) {
			size10 = multi(radix10, size10, 2, 10);
			size10 = plus(radix10, size10, radix2[i] - '0', 10);
		}
		for (int i = 0; i < size10; i++) {
			printf("%c", radix10[i]);
		}
		printf("\n");
	}
	return 0;
}