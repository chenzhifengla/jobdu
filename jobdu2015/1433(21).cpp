#include <stdio.h>
#include <algorithm>
using namespace std;
struct room {
	int javaBeans;
	int catfood;
	double price;
	bool operator < (const room &b) const {
		return price > b.price;
	}
};

int main() {
	room r[1001];
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF && !(m == -1 && n == -1)) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &r[i].javaBeans, &r[i].catfood);
			r[i].price = (double)r[i].javaBeans / (double)r[i].catfood;
		}
		sort(r, r + n);
		double food = 0;
		int pos = 0;
		while (pos < n) {
			if (r[pos].catfood > m) {
				food += m * r[pos].price;
				break;
			}
			else if (r[pos].catfood == m) {
				food += r[pos].javaBeans;
				break;
			}
			else {
				food += r[pos].javaBeans;
				m -= r[pos].catfood;
				pos++;
			}
		}
		printf("%.3lf\n", food);
	}
	return 0;
}