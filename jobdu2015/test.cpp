#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main() {
	char s[] = { 'a', 'b', 'c', 0 };
	std::string t;
	t.resize(1);
	printf("t=%p, &t[0]=%p, &t[1]=%p\n", t, &t[0], &t[1], t.size);
	printf("s=%p, &s[0]=%p\n", s, &s[0]);
	scanf("%s", t);
	cout << t << endl;
	std::string a = "AAAA";
	std::string b = "BBB";
	a.insert(2, b);
	std::cout << a << std::endl << b << std::endl;
	return 0;
}