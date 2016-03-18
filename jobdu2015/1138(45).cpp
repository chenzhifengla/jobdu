#include <stdio.h>
#include <string.h>
int main() {
	char num[50];
	while (scanf("%s", num) != EOF) {
		int numnum[50];
		int len = strlen(num);
		for (int i = 0; i < len; i++) {
			numnum[i] = num[i] - '0';
		}
		int radix2[200];
		int index = 0;
		int numlen = len;
		while (numlen) {
			int remain = 0;
			for (int i = len - numlen; i < len; i++) {
				int thisnum = numnum[i] + remain * 10;
				remain = thisnum % 2;
				numnum[i] = thisnum / 2;
			}
			radix2[index++] = remain;
			if (numnum[len - numlen] == 0) {
				numlen--;
			}
		}
		for (int i = index - 1; i >= 0; i--) {
			printf("%d", radix2[i]);
		}
		printf("\n");
	}
	return 0;
}