#include <stdio.h>
#include <string.h>
#include <algorithm>
struct bigInteger {
	char num[1010];
	int size;
	bool operator < (const bigInteger &b) const {
		if (size != b.size) return size < b.size;
		else {
			for (int i = 0; i < size; i++) {
				if (num[i] != b.num[i])
					return num[i] < b.num[i];
			}
			return true;	//到此处其实两数相等
		}
	}
};
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		bigInteger buf[101];
		for (int i = 0; i < n; i++) {
			scanf("%s", buf[i].num);
			buf[i].size = strlen(buf[i].num);
		}
		std::sort(buf, buf + n);
		for (int i = 0; i < n; i++) {
			printf("%s\n", buf[i].num);
		}
	}
	return 0;
}