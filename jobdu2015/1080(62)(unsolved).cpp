#include <stdio.h>

int char2num(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
	else return c - 'a' + 10;
}

int num2char(int n) {
	if (n < 10) return n + '0';
	else return n - 10 + 'a';
}

int multim(char radixn[], int size, int m, int n) {
	//将该表示n进制数的数组乘上m
	int current = 0;
	for (int i = 0; i < size; i++) {
		int num = char2num(radixn[i]) * m + current;
		radixn[i] = num2char(num % n);
		current = num / n;
	}
	while (current > 0) {
		radixn[size++] = num2char(current % n);
		current /= n;
	}
	return size;
}

int plusm(char radixn[], int size, int plus, int n) {
	//将表示n进制的数组加上plus
	int index = 0;
	while (plus > 0) {
		int num = char2num(radixn[index]) + plus;
		radixn[index++] = num2char(num % n);
		plus = num / n;
	}
	return size > index ? size : index;
}


void print(char radixn[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		printf("%c", radixn[i]);
	}
	printf("\n");
}

int main() {
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF) {
		char radixm[10000];
		scanf("%s", radixm);
		char radixn[10000];
		for (int i = 0; i < 10000; i++) radixn[i] = '0';
		int sizen = 0;
		for (int i = 0; radixm[i]; i++) {
			sizen = multim(radixn, sizen, m, n);
			sizen = plusm(radixn, sizen, char2num(radixm[i]), n);
		}
		print(radixn, sizen);
	}
	return 0;
}