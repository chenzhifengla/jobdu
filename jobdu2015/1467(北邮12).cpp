#include <stdio.h>
struct tree {
	tree* leftchild;
	tree* rightchild;
	int value;
}buf[110];
int loc;
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		loc = 0;
		for (int i = 0; i < n; i++) {
			buf[i].leftchild = buf[i].rightchild = NULL;
			buf[i].value = -1;
		}
		tree* root = &buf[0];
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (root->value < 0) {
				root->value = x;
				loc++;
				printf("-1\n");
				continue;
			}
			else {
				tree* thisnode = root;
				tree* lastnode = NULL;
				while (thisnode) {
					lastnode = thisnode;
					if (x >= thisnode->value) {
						thisnode = thisnode->rightchild;
					}
					else {
						thisnode = thisnode->leftchild;
					}
				}
				printf("%d\n", lastnode->value);
				buf[loc].value = x;
				if (x >= lastnode->value) {
					lastnode->rightchild = &buf[loc];
				}
				else {
					lastnode->leftchild = &buf[loc];
				}
				loc++;
			}
		}
	}
	return 0;
}