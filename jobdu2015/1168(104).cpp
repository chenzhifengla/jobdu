#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <ctype.h>
using namespace std;

int main() {
	char str[101];
	scanf("%s", str);
	getchar();
	string a = str;
	for (int i = 0; i < a.size(); i++) {
		a[i] = tolower(a[i]);
	}
	while (scanf("%[^\n]", str) != EOF) {
		getchar();
		if (strlen(str) == 0) {
			printf("\n");
			continue;
		}
		string b = str, c = b;
		for (int i = 0; i < b.size(); i++) {
			b[i] = tolower(b[i]);
		}
		int t = b.find(a, 0);
		while (t != string::npos) {
			c.erase(t, a.size());
			b.erase(t, a.size());
			t = b.find(a, t);
		}
		t = c.find(' ', 0);
		while (t != string::npos) {
			c.erase(t, 1);
			t = c.find(' ', 0);
		}
		printf("%s\n", c.c_str());
		str[0] = 0;
	}
	return 0;
}