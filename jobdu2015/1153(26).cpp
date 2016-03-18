#include <stdio.h>
#include <stack>
using namespace std;
int main() {
	char buf[110];
	while (scanf("%s", buf) != EOF) {
		printf("%s\n", buf);
		stack<int> S;
		bool flag[110] = { false };
		for (int i = 0; buf[i] != 0; i++){
			if (buf[i] == '(') {
				S.push(i);
			}
			else if (buf[i] == ')') {
				if (S.empty() == false) {
					flag[S.top()] = true;
					S.pop();
					flag[i] = true;
				}
			}
		}
		for (int i = 0; buf[i] != 0; i++) {
			if (buf[i] == '(') {
				if (flag[i] == true)
					printf(" ");
				else
					printf("$");
			}
			else if (buf[i] == ')') {
				if (flag[i] == true)
					printf(" ");
				else
					printf("?");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}