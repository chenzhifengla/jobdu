#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n;
	int a[101];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int m;
		scanf("%d", &m);
		int top = n - 1;
		int base = 0;
		int mid;
		for (int i = 0; i < m; i++) {
			int t;
			scanf("%d", &t);
			int flag = 0;
			base = 0;
			top = n - 1;
			while (base <= top) {
				mid = (base + top) / 2;
				if (a[mid] == t) {
					printf("YES\n");
					flag = 1;
					break;
				}
				else if (a[mid] < t) {
					base = mid + 1;
				}
				else {
					top = mid - 1;
				}
			}
			if (flag == 0)
				printf("NO\n");
		}
	}
	return 0;
}