#include<stdio.h>
#include<algorithm>
int main() {
	char s[201];
	while (scanf("%s", s) != EOF) {
		int length;
		for (length = 0; s[length]; length++);
		std::sort(s, s + length);
		printf("%s\n", s);
	}
	return 0;
}