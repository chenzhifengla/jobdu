#include <stdio.h>
#include <queue>
using namespace std;
struct N {
	int a, b, c;
	int times;
};
queue<N> Q;
bool mark[101][101][101];

int AtoB(int a, int b, int c, int sa, int sb, int sc, int all, int times) {
	if (sb - b >= a) {
		b += a;
		a = 0;
	}
	else {
		a -= (sb - b);
		b = sb;
	}
	if (!mark[a][b][c]) {
		mark[a][b][c] = true;
		N tmp;
		tmp.a = a;
		tmp.b = b;
		tmp.c = c;
		tmp.times = times + 1;
		if ((a == all / 2 && b == all / 2) ||
			(a == all / 2 && c == all / 2) ||
			(b == all / 2 && c == all / 2)) {
			return tmp.times;
		}
		Q.push(tmp);
	}
	return -1;
}


int BFS(int n, int m, int s) {
	while (!Q.empty()) {
		N now = Q.front();
		Q.pop();
		int times;

		//a倒向b
		times = AtoB(now.a, now.b, now.c, n, m, s, s, now.times);
		if (times > 0) return times;
		
		//b倒向a
		times = AtoB(now.b, now.a, now.c, m, n, s, s, now.times);
		if (times > 0) return times;

		//a倒向c
		times = AtoB(now.a, now.c, now.b, n, s, m, s, now.times);
		if (times > 0) return times;

		//c倒向a
		times = AtoB(now.c, now.a, now.b, s, n, m, s, now.times);
		if (times > 0) return times;

		//b倒向c
		times = AtoB(now.b, now.c, now.a, m, s, n, s, now.times);
		if (times > 0) return times;

		//c倒向b
		times = AtoB(now.c, now.b, now.a, s, m, n, s, now.times);
		if (times > 0) return times;
	}
	return -1;
}

int main() {
	int n, m, s;
	while (scanf("%d%d%d", &s, &n, &m) != EOF) {
		if (n == 0 && m == 0 && s == 0) break;
		if (s % 2 != 0) {
			printf("NO\n");
			continue;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < s; k++) {
					mark[i][j][k] = false;
				}
			}
		}
		while (!Q.empty()) Q.pop();
		N tmp;
		tmp.a = tmp.b = 0;
		tmp.c = s;
		Q.push(tmp);
		mark[0][0][s] = true;
		int times = BFS(n, m, s);
		if (times == -1) {
			printf("NO\n");
		}
		else {
			printf("%d\n", times);
		}
	}
	return 0;
}