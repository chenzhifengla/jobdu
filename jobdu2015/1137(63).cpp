#include <stdio.h>
struct floatnum {
	char integer[200];
	int intsize;
	char decimal[200];
	int decsize;
};

floatnum num2struct(char num[]) {
	int point = 0;
	for (; num[point] != '.'; point++);
	floatnum num2;
	num2.intsize = num2.decsize = 0;
	for (int i = point - 1; i >= 0; i--) {
		num2.integer[num2.intsize++] = num[i];
	}
	for (int i = num2.intsize; i < 200; i++) {
		num2.integer[i] = '0';
	}
	for (int i = point + 1; num[i]; i++) {
		num2.decimal[num2.decsize++] = num[i];
	}
	for (int i = num2.decsize; i < 200; i++) {
		num2.decimal[i] = '0';
	}
	return num2;
}

floatnum numplus(floatnum num1, floatnum num2) {
	floatnum num;
	num.intsize = num1.intsize > num2.intsize ? num1.intsize : num2.intsize;
	num.decsize = num1.decsize > num2.decsize ? num1.decsize : num2.decsize;

	int current = 0;
	for (int i = num.decsize - 1; i >= 0; i--) {
		int n = num1.decimal[i] - '0' + num2.decimal[i] - '0' + current;
		if (n > 9) {
			num.decimal[i] = n % 10 + '0';
			current = 1;
		}
		else {
			num.decimal[i] = n + '0';
			current = 0;
		}
	}
	for (int i = num.decsize - 1; i >= 0; i--) {
		if (num.decimal[i] != '0') break;
		else {
			num.decsize--;
		}
	}

	for (int i = 0; i < num.intsize; i++) {
		int n = num1.integer[i] - '0' + num2.integer[i] - '0' + current;
		if (n > 9) {
			num.integer[i] = n % 10 + '0';
			current = 1;
		}
		else {
			num.integer[i] = n + '0';
			current = 0;
		}
	}
	if (current > 0) {
		num.integer[num.intsize++] = current + '0';
	}
	return num;
}

void numout(floatnum num) {
	for (int i = num.intsize - 1; i >= 0; i--) {
		printf("%c", num.integer[i]);
	}
	printf(".");
	for (int i = 0; i < num.decsize; i++) {
		printf("%c", num.decimal[i]);
	}
	printf("\n");
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			char num1[200], num2[200];
			scanf("%s%s", num1, num2);
			floatnum fnum1, fnum2, fnum3;
			fnum1 = num2struct(num1);
			fnum2 = num2struct(num2);
			fnum3 = numplus(fnum1, fnum2);
			numout(fnum3);
		}
	}
	return 0;
}