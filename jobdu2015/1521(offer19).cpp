#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int value;
	Node* left;
	Node* right;
};

void rollTree(Node* tree) {
	Node* t = tree->left;
	tree->left = tree->right;
	tree->right = t;

	if (tree->left != NULL) {
		rollTree(tree->left);
	}
	if (tree->right != NULL) {
		rollTree(tree->right);
	}
}

void preOrderTraverse(Node* tree) {
	printf(" %d", tree->value);
	if (tree->left != NULL) preOrderTraverse(tree->left);
	if (tree->right != NULL) preOrderTraverse(tree->right);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) {
			printf("NULL\n");
			continue;
		}
		Node* tree1 = (Node*)malloc(sizeof(Node)*n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			tree1[i].value = x;
			tree1[i].left = tree1[i].right = NULL;
		}
		for (int i = 0; i < n; i++) {
			char command[5];
			scanf("%s", command);
			if (command[0] == 'd') {
				int l, r;
				scanf("%d%d", &l, &r);
				tree1[i].left = &tree1[l - 1];
				tree1[i].right = &tree1[r - 1];
			}
			else if (command[0] == 'l') {
				int l;
				scanf("%d", &l);
				tree1[i].left = &tree1[l - 1];
			}
			else if (command[0] == 'r') {
				int r;
				scanf("%d", &r);
				tree1[i].right = &tree1[r - 1];
			}
		}
		rollTree(tree1);
		printf("%d", tree1->value);
		if (tree1->left != NULL) preOrderTraverse(tree1->left);
		if (tree1->right != NULL) preOrderTraverse(tree1->right);
		printf("\n");
		free(tree1);
	}
	return 0;
}