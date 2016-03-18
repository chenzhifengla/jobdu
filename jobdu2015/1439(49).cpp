
#include <stdio.h>
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			int lcm = 1;
			for (int j = 0; j < m; j++) {
				int x;
				scanf("%d", &x);
				lcm = lcm / gcd(lcm, x) * x;
			}
			printf("%d\n", lcm);
		}
	}
	return 0;
}

/*
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int count_LCM(int a, int b)
{
	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int n;
	while (scanf("%d", &n))
	{
		while (n > 0)
		{
			int num;
			scanf("%d", &num);
			int *data = (int *)malloc(sizeof(int) * num);
			int i;
			for (i = 0; i < num; i++)
				scanf("%d", &data[i]);
			int result = data[0] / count_LCM(data[0], data[1]) * data[1];

			for (i = 2; i < num; i++)
				result = result  / count_LCM(result, data[i]) * data[i];
			printf("%d\n", result);
			free(data);
			n--;
		}
	}
}
*/