#include<stdio.h>
char buf[81][81];
int main() {
	int n;
	char inner, outer;
	bool firstcase = true;
	while (scanf("%d %c %c", &n, &inner, &outer) != EOF) {
		if (firstcase == true) firstcase = false;
		else printf("\n");
		int innerX, innerY;
		innerX = innerY = (n + 1) / 2 - 1;
		for (int i = 0; i < (n + 1) / 2; i++) {
			char c = i % 2 == 0 ? inner : outer;
			int pX = innerX - i;
			int pY = innerY - i;
			int length = i * 2 + 1;
			for (int j = 0; j < length; j++) {
				buf[pX][pY + j] = c;
				buf[pX + length - 1][pY + j] = c;
			}
			for (int j = 0; j < length; j++) {
				buf[pX + j][pY] = c;
				buf[pX + j][pY + length - 1] = c;
			}
		}
		if (n != 1) {
			buf[0][0] = buf[0][n - 1] = buf[n - 1][0] = buf[n - 1][n - 1] = ' ';
		}		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", buf[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}