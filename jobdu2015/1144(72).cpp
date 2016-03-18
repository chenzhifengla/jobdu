#include <stdio.h>
#include <math.h>
#include <algorithm>
struct Point {
	double x, y;
	double getDistance(Point b) {
		return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
	}
}point[101];
struct Edge {
	int a, b;
	double distance;
	bool operator < (const Edge &c) const {
		return distance < c.distance;
	}
}edge[6000];

int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		tree[n] = findRoot(tree, tree[n]);
		return tree[n];
	}
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		int edgenum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double dis = point[i].getDistance(point[j]);
				edge[edgenum].a = i;
				edge[edgenum].b = j;
				edge[edgenum].distance = dis;
				edgenum++;
			}
		}
		std::sort(edge, edge + edgenum);
		int tree[101];
		for (int i = 0; i < n; i++) tree[i] = -1;
		double ans = 0;
		for (int i = 0; i < edgenum; i++) {
			int a = findRoot(tree, edge[i].a);
			int b = findRoot(tree, edge[i].b);
			if (a != b) {
				tree[a] = b;
				ans += edge[i].distance;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}