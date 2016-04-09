#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main() {
	char str[100];
	//string str;
	while (scanf("%s", str) != EOF) {
		int n;
		scanf("%d", &n);
		//cin >> n;
		for (int i = 0; i < n; i++) {
			char buf[100];
			scanf("%s", buf);
			int command, start, len;
			command = buf[0] - '0';
			start = buf[1] - '0';
			len = buf[2] - '0';
			if (command == 0) {
				char tmp;
				int j, k;
				for (j = start, k = start + len - 1; j < k; j++, k--) {
					tmp = str[j];
					str[j] = str[k];
					str[k] = tmp;
				}
				/*
				int half = start + (len - 1) / 2;
				for (int j = start; j <= half; j++) {
					char c = str[2 * start + len - 1 - j];
					str[2 * start + len - 1 - j] = str[j];
					str[j] = c;
				}
				*/
			}
			else {
				for (int j = start; j < start + len; j++) {
					str[j] = buf[j - start + 3];
				}
			}
			printf("%s\n", str);
			//cout << str << endl;
		}
	}
	return 0;
}