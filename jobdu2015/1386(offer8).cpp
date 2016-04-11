#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int* buf = new int[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		int start = 0, end = n - 1;
		if (buf[start] < buf[end]) {
			printf("%d\n", buf[start]);
		}
		else {
			while (end - start > 1) {
				int midle = (start + end) / 2;
				if (buf[midle] == buf[start] && buf[midle] == buf[end]) {
					int position;
					for (position = start + 1; position <= end; position++) {
						if (buf[position] < buf[position - 1]) {
							break;
						}
					}
					if (position > end) position = end;
					end = position;
					break;
				}
				if (buf[midle] >= buf[start]) {
					start = midle;
					continue;
				}
				if (buf[midle] <= buf[end]) {
					end = midle;
					continue;
				}
			}
			printf("%d\n", buf[end]);
		}
		delete[] buf;
	}
	return 0;
}