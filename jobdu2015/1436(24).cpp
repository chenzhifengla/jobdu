#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int x, int y) {
	return x > y;
}
int main() {
	int l, n;
	int a[610];
	while (scanf("%d%d", &l, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n, cmp);
		int num = 0;
		for (int i = 0; i < n; i++) {
			if (l == 0) break;
			if (a[i] <= l) {
				l -= a[i];
				num++;
			}
			else {		//she can cut the block
				l = 0;
				num++;
			}
		}
		if (l == 0) {
			printf("%d\n", num);
		}
		else {
			printf("impossible\n");
		}
	}
	return 0;
}