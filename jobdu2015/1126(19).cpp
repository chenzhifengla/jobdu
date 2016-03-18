#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int buf[100];
		int des[100];
		for (int i = 0; i < n; i++) {
			int len = 0;
			scanf("%d", &len);
			for (int j = 0; j < len; j++) {
				scanf("%d", &buf[j]);
			}
			int size = 0;
			if (buf[0] != buf[1]) {
				des[size++] = 0;
			}
			for (int j = 1; j < len - 1; j++) {
				if ((buf[j] > buf[j - 1] && buf[j] > buf[j + 1]) || buf[j] < buf[j - 1] && buf[j] < buf[j + 1]) {
					des[size++] = j;
				}
			}
			if (buf[len - 1] != buf[len - 2]) {
				des[size++] = len - 1;
			}
			printf("%d", des[0]);
			for (int j = 1; j < size; j++) {
				printf(" %d", des[j]);
			}
			printf("\n");
		}
	}
	return 0;
}