#include <stdio.h>
#include <stack>
using namespace std;
int main() {
	int a;
	while (scanf("%d", &a) != EOF) {
		stack<double> in;
		in.push((double)a);
		char op;
		int b;
		while (scanf("%c", &op) != EOF) {
			if (op == '\n' || op == '\r') break;
			scanf("%d", &b);
			switch (op) {
			case '+':in.push(b); break;
			case '-':in.push(-b); break;
			case '*':in.top() *= b; break;
			case '/':in.top() /= b; break;
			}
		}
		double result = 0;
		while (!in.empty()) {
			result += in.top();
			in.pop();
		}
		printf("%d\n", (int)result);
	}
	return 0;
}