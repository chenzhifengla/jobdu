#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		char c;
		cin >> c;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == c) {
				str.erase(i, 1);
				i--;
			}
		}
		cout << str << endl;
	}
	return 0;
}