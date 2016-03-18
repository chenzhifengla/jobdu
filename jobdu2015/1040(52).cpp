#include <stdio.h>
bool prime[500000] = { false };
int primenum[500000];
int main() {
	
	for (int i = 2; i <= 250000; i++) {
		int bound = 500000 / i + 1;
		for (int j = 2; j <= bound; j++) {
			prime[i * j] = true;
		}
	}
	
	int index = 1;
	for (int i = 2; i <= 500000; i++) {
		if (!prime[i]) primenum[index++] = i;
	}
	int k;
	while (scanf("%d", &k) != EOF) {
		printf("%d\n", primenum[k]);
	}
	return 0;
}