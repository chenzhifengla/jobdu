#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int c;
	scanf("%d", &c);
	for (int j = 0; j < c; j++) {
		int n, v, w;
		scanf("%d%d%d", &n, &v, &w);
		int pi[101];
		for (int i = 0; i < n; i++) {
			scanf("%d", &pi[i]);
		}
		sort(pi, pi + n);
		int maxV = 0;
		double p = 0;
		int pos = 0;
		for (; pos < n; pos++) {
			double t = (double)(maxV*p + v*pi[pos]) / (double)(maxV + v);
			if (t <= w) {
				maxV += v;
				p = t;
			}
			else break;
		}
		printf("%d %.2lf\n", maxV, p / 100);
	}
	return 0;
}