#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int main() {
	char str[101];
	while (scanf("%[^\n]", str) != EOF) {
		getchar();
		char first[101], second[101];
		scanf("%s%s", first, second);
		if (strlen(str) == 0) {
			printf("\n");
			continue;
		}
		string a = str;
		getchar();
		string c = first, d = second;
		int t = a.find(c, 0);
		while (t != string::npos) {
			a.erase(t, c.size());
			a.insert(t, d);
			t = a.find(c, t);
		}
		printf("%s\n", a.c_str());
		str[0] = '\0';
	}
	return 0;
}