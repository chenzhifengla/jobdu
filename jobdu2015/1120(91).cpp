#include <stdio.h>
#include <string.h>
char str[10];
int len;
char output[10];
bool mark[10];

void DFS(int size) {
	if (size == len) {
		output[size] = '\0';
		printf("%s\n", output);
		return;
	}
	for (int i = 0; i < len; i++) {
		if (mark[i]) continue;
		mark[i] = true;
		output[size] = str[i];
		DFS(size + 1);
		mark[i] = false;
	}
	return;
}

int main() {
	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		for (int i = 0; i < len; i++) mark[i] = false;
		DFS(0);
		printf("\n");
	}
}