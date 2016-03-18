#include<stdio.h>
#include <algorithm>
using namespace std;
struct show {
	int begin;
	int end;
	bool operator < (const show &b) const {
		return end < b.end;
	}
}buf[101];

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &buf[i].begin, &buf[i].end);
		}
		sort(buf, buf + n);
		int time = 0;
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (time <= buf[i].begin) {
				//watch it
				num++;
				time = buf[i].end;
			}
		}
		printf("%d\n", num);
	}
	return 0;
}