#include<stdio.h>
#include<stack>

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		std::stack<int> S;
		while (!S.empty()) S.pop();
		for (int i = 0; i < n; i++) {
			char c[10];
			scanf("%s", c);
			if (c[0] == 'A') {
				if (S.empty()) {
					printf("E\n");
				}
				else {
					printf("%d\n", S.top());
				}
			}
			else if (c[0] == 'O') {
				if (!S.empty()) {
					S.pop();
				}
			}
			else {
				int num;
				scanf("%d", &num);
				S.push(num);
			}
		}
		printf("\n");
	}
	return 0;
}