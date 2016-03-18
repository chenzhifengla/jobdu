#include <stdio.h>
#define M 9973
/*
void matrixMulti(int m[][11], int n) {
	int m2[11][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += m[i][k] * m[k][j];
			}
			m2[i][j] = sum % M;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = m2[i][j];
		}
	}
}
*/

void matrixMulti(int ans[][11], int m[][11], int n) {
	int m2[11][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum = (sum + m[i][k] * m[k][j]) % M;
			}
			m2[i][j] = sum % M;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = m2[i][j];
		}
	}
}

int matrixTr(int ans[][11], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = (sum + ans[i][i]) % M;
	}
	sum %= M;
	return sum;
}

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		for (int r = 0; r < t; r++) {
			int n, k;
			scanf("%d%d", &n, &k);
			int matrix[11][11];
			int ans[11][11];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					scanf("%d", &matrix[i][j]);
					ans[i][j] = matrix[i][j];
				}
			}
			k--;
			while (k != 0) {
				if (k % 2 == 1) {
					matrixMulti(ans, matrix, n);
				}
				k /= 2;
				matrixMulti(matrix, matrix, n);
			}
			printf("%d\n", matrixTr(ans, n));
		}
	}
	return 0;
}