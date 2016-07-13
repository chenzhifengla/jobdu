#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int value;
	Node* left;
	Node* right;
};

bool compareTree(Node* tree1, Node* tree2) {
	if (tree1->value != tree2->value) return false;

	if (tree2->left != NULL) {
		if (tree1->left == NULL) {
			return false;
		}
		if (!compareTree(tree1->left, tree2->left)) return false;
	}

	if (tree2->right != NULL) {
		if (tree1->right == NULL) {
			return false;
		}
		if (!compareTree(tree1->right, tree2->right)) return false;
	}
	return true;
}

bool searchTree(Node* tree1, Node* tree2) {
	if (tree2 == NULL) return false;
	if (tree1->value == tree2->value) {
		if (compareTree(tree1, tree2)) {
			return true;
		}
	}
	if (tree1->left != NULL) {
		if (searchTree(tree1->left, tree2)) {
			return true;
		}
	}
	if (tree1->right != NULL) {
		if (searchTree(tree1->right, tree2)) {
			return true;
		}
	}
	return false;
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (n == 0) {
			for (int i = 0; i < m; i++) {
				int num;
				scanf("%d", &num);
			}
			for (int i = 0; i < m; i++) {
				int num;
				scanf("%d", &num);
				if (num == 2) {
					int l, r;
					scanf("%d%d", &l, &r);
				}
				else if (num == 1) {
					int l;
					scanf("%d", &l);
				}
			}
			printf("NO\n");
			continue;
		}
		if (m == 0) {
			for (int i = 0; i < n; i++) {
				int num;
				scanf("%d", &num);
			}
			for (int i = 0; i < n; i++) {
				int num;
				scanf("%d", &num);
				if (num == 2) {
					int l, r;
					scanf("%d%d", &l, &r);
				}
				else if (num == 1) {
					int l;
					scanf("%d", &l);
				}
			}
			printf("NO\n");
			continue;
		}
		Node* tree1 = (Node*)malloc(sizeof(Node) * n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			tree1[i].value = x;
			tree1[i].left = tree1[i].right = NULL;
		}
		for (int i = 0; i < n; i++) {
			int num;
			scanf("%d", &num);
			if (num == 2) {
				int l, r;
				scanf("%d%d", &l, &r);
				tree1[i].left = &tree1[l - 1];
				tree1[i].right = &tree1[r - 1];
			}
			else if (num == 1) {
				int l;
				scanf("%d", &l);
				tree1[i].left = &tree1[l - 1];
			}
		}

		Node* tree2 = (Node*)malloc(sizeof(Node) * m);
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			tree2[i].value = x;
			tree2[i].left = tree2[i].right = NULL;
		}
		for (int i = 0; i < m; i++) {
			int num;
			scanf("%d", &num);
			if (num == 2) {
				int l, r;
				scanf("%d%d", &l, &r);
				tree2[i].left = &tree2[l - 1];
				tree2[i].right = &tree2[r - 1];
			}
			else if (num == 1) {
				int l;
				scanf("%d", &l);
				tree2[i].left = &tree2[l - 1];
			}
		}

		if (searchTree(tree1, tree2)) {
			printf("YES\n");
		}
		else printf("NO\n");

		free(tree1);
		free(tree2);
	}
	return 0;
}