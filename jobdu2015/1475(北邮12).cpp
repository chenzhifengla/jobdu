#include <stdio.h>
#include <string.h>
int getNum(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'a' && c <= 'z') {
		return c - 'a' + 10;
	}
	else return c - 'A' + 10;
}
char buf[1000];
char end[1000];
int main() {
	int t;
	scanf("%d", &t);
	//getchar();
	scanf("%[\n\r ]", end);
	//gets(buf);
	for (int x = 1; x <= t; x++) {
		scanf("%[^\n]", buf);
		//getchar();
		scanf("%[\n\r ]", end);
		int off = getNum(buf[1]);
		off = (off - 5) * 12;
		printf("Case #%d\nTotal length = ", x);
		printf("%d bytes\nSource = ", 
			16 * 16 * 16 * getNum(buf[6]) +
			16 * 16 * getNum(buf[7]) +
			16 * getNum(buf[9]) + 
			getNum(buf[10]));
		printf("%d.%d.%d.%d\nDestination = ", 
			16 * getNum(buf[36]) + getNum(buf[37]),
			16 * getNum(buf[39]) + getNum(buf[40]),
			16 * getNum(buf[42]) + getNum(buf[43]),
			16 * getNum(buf[45]) + getNum(buf[46]));
		printf("%d.%d.%d.%d\nSource Port = ",
			16 * getNum(buf[48]) + getNum(buf[49]),
			16 * getNum(buf[51]) + getNum(buf[52]),
			16 * getNum(buf[54]) + getNum(buf[55]),
			16 * getNum(buf[57]) + getNum(buf[58]));
		printf("%d\nDestination Port = ",
			16 * 16 * 16 * getNum(buf[60 + off]) +
			16 * 16 * getNum(buf[61 + off]) +
			16 * getNum(buf[63 + off]) +
			getNum(buf[64 + off]));
		printf("%d\n\n",
			16 * 16 * 16 * getNum(buf[66 + off]) +
			16 * 16 * getNum(buf[67 + off]) +
			16 * getNum(buf[69 + off]) +
			getNum(buf[70 + off]));
	}
	return 0;
}

/*
#include<stdio.h>
#include<string.h>
char str[1000];
int ctoi(char *a) {
	int result;
	if (*a >= '0'&&*a <= '9') {
		result = *a - '0';
	}
	else if (*a >= 'a'&&*a <= 'f') {
		result = *a - 'a' + 10;
	}
	return result;
}

int ctoi1(char *a) {
	int result;
	result = ctoi(a) * 16 + ctoi(a + 1);
	return result;
}
int ctoi2(char *a) {
	int result;
	result = ctoi(a) * 256 * 16 + ctoi(a + 1) * 256 + ctoi(a + 3) * 16 + ctoi(a + 4);
	return result;
}

int main() {
	int t;
	scanf("%d", &t);
	gets(str);
	for (int i = 1; i <= t; i++) {
		gets(str);
		int IHL;
		IHL = ctoi(str + 1) * 4;
		printf("Case #%d\n", i);

		printf("Total length = %d bytes\n", ctoi2(str + 6));

		printf("Source = %d.%d.%d.%d\n", ctoi1(str + 36), ctoi1(str + 39), ctoi1(str + 42), ctoi1(str + 45));
		printf("Destination = %d.%d.%d.%d\n", ctoi1(str + 48), ctoi1(str + 51), ctoi1(str + 54), ctoi1(str + 57));
		printf("Source Port = %d\n", ctoi2(str + IHL * 3));
		printf("Destination Port = %d\n", ctoi2(str + IHL * 3 + 6));
		printf("\n");
	}
}
*/