#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		priority_queue<int, vector<int>, greater<int> > Q;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			Q.push(x);
		}
		int ans = 0;
		while (Q.size() > 1) {
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			int c = a + b;
			Q.push(c);
			ans += c;
		}
		printf("%d\n", ans);
	}
	return 0;
}