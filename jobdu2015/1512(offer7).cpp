#include <stdio.h>
#include <stack>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	char command[10];
	stack<int> S1, S2;
	while (!S1.empty()) S1.pop();
	while (!S2.empty()) S2.pop();
	for (int i = 0; i < n; i++) {
		scanf("%s", command);
		if (command[1] == 'U') {
			int num;
			scanf("%d", &num);
			S1.push(num);
		}
		else if (!S2.empty()) {
			printf("%d\n", S2.top());
			S2.pop();
		}
		else if (S1.empty()) {
			printf("-1\n");
		}
		else {
			while (!S1.empty()) {
				int num = S1.top();
				S1.pop();
				S2.push(num);
			}
			printf("%d\n", S2.top());
			S2.pop();
		}
	}
	return 0;
}