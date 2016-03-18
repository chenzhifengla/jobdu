#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char tplate[6][6];
char res[3001][3001];
char des[3001][3001];
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		getchar();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%c", &tplate[i][j]);
				des[i][j] = tplate[i][j];
			}
			getchar();
		}
		int times;
		scanf("%d", &times);
		int length = 1;
		for (int i = 1; i < times; i++) {
			length *= n;
			for (int j = 0; j < length; j++) {
				for (int k = 0; k < length; k++) {
					res[j][k] = des[j][k];
				}
			}
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					for (int p = 0; p < length; p++) {
						for (int q = 0; q < length; q++) {
							if (tplate[j][k] != ' ')
								des[j*length + p][k*length + q] = res[p][q];
							else
								des[j*length + p][k*length + q] = ' ';
						}
					}
				}
			}
		}
		length *= n;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				printf("%c", des[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}