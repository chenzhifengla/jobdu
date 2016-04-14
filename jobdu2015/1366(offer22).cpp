#include <stdio.h>
#include <stack>
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		std::stack<int> first;
		while (!first.empty()) first.pop();
		int* buf = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);

		}
	}
}