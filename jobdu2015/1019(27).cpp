/*
#include <stdio.h>
#include <stack>
using namespace std;
char str[220];
int mat[][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0,
};
stack<int> op;
stack<double> in;

void getOp(bool &reto, int &retn, int &i) {
	if (i == 0 && op.empty() == true) {
		reto = true;
		retn = 0;
		return;
	}
	if (str[i] == 0) {
		reto = true;
		retn = 0;
		return;
	}
	if (str[i] >= '0' && str[i] <= '9') {
		reto = false;
	}
	else {
		reto = true;
		if (str[i] == '+') {
			retn = 1;
		}
		else if (str[i] == '-') {
			retn = 2;
		}
		else if (str[i] == '*') {
			retn = 3;
		}
		else if (str[i] == '/') {
			retn = 4;
		}
		i += 2;
		return;
	}
	retn = 0;
	for (; str[i] != ' ' && str[i] != 0; i++) {
		retn *= 10;
		retn += str[i] - '0';
	}
	if (str[i] == ' ') {
		i++;
	}
	return;
}

int main() {
	while (scanf("%[^\n]", str) != EOF) {
		getchar();
		if (str[0] == '0' && str[1] == 0) break;
		bool retop;
		int retnum;
		int idx = 0;
		while (!op.empty())	op.pop();
		while (!in.empty()) in.pop();
		while (true) {
			getOp(retop, retnum, idx);
			if (retop == false) {
				in.push((double)retnum);
			}
			else {
				double tmp;
				if (op.empty() == true || mat[retnum][op.top()] == 1) {
					op.push(retnum);
				}
				else {
					while (mat[retnum][op.top()] == 0) {
						int ret = op.top();
						op.pop();
						double b = in.top();
						in.pop();
						double a = in.top();
						in.pop();
						if (ret == 1) tmp = a + b;
						else if (ret == 2) tmp = a - b;
						else if (ret == 3) tmp = a * b;
						else tmp = a / b;
						in.push(tmp);
					}
					op.push(retnum);
				}
			}
			if (op.size() == 2 && op.top() == 0) break;
		}
		printf("%.2f\n", in.top());
	}
	return 0;
}
*/

//自己写的解法
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
stack<char> op;
stack<double> in;

void popandcalc() {
	char opera = op.top();
	op.pop();
	double b = in.top();
	in.pop();
	double a = in.top();
	in.pop();
	double result = 0;
	switch (opera) {
	case '+':result = a + b; break;
	case '-':result = a - b; break;
	case '*':result = a * b; break;
	case '/':result = a / b; break;
	}
	in.push(result);
}

int main() {
	char str[220];
	while (scanf("%[^\n]", str) != EOF) {
		getchar();
		if (str[0] == '0' && str[1] == '\0') break;
		while (!op.empty()) op.pop();
		while (!in.empty()) in.pop();
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				int num = 0;
				for (; str[i] != ' ' && i < len; i++) {
					num *= 10;
					num += str[i] - '0';
				}
				in.push((double)num);
			}
			else if (str[i] == ' ') {
				continue;
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!op.empty()) popandcalc();
				op.push(str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
					popandcalc();
				op.push(str[i]);
			}
		}
		while (!op.empty()) popandcalc();
		printf("%.2f\n", in.top());
	}
}

