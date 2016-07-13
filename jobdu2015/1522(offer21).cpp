#include <stdio.h>
#include <stack>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		std::stack<int> Q;
		std::stack<int> min;
		while (!Q.empty()) Q.pop();
		while (!min.empty()) min.pop();
		for (int i = 0; i < n; i++) {
			char command[5];
			scanf("%s", command);
			if (command[0] == 's') {
				int num;
				scanf("%d", &num);
				Q.push(num);
				if (min.empty()) {
					min.push(num);
					printf("%d\n", num);
				}
				else {
					int minNum = min.top();
					if (num < min.top()) {
						min.push(num);
						printf("%d\n", num);
					}
					else {
						min.push(minNum);
						printf("%d\n", minNum);
					}
				}
			}
			else {
				if (!Q.empty()) {
					Q.pop();
					min.pop();
					if (!Q.empty()) {
						printf("%d\n", min.top());
					}
					else {
						printf("NULL\n");
					}
				}
				else {
					printf("NULL\n");
				}
			}
		}
	}
	return 0;
}