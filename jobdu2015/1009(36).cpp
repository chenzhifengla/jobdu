#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	node* left;
	node* right;
	char val;
};

node* insertNode(node* root, char c) {
	if (!root) {
		root = (node*)malloc(sizeof(node));
		root->left = root->right = NULL;
		root->val = c;
	}
	else if (c < root->val) {
		root->left = insertNode(root->left, c);
	}
	else root->right = insertNode(root->right, c);
	return root;
}

node* buildTree(char* s) {
	node* root = NULL;
	for (char* c = s; *c; c++) {
		root = insertNode(root, *c);
	}
	return root;
}

bool treeCmp(node* root, node* rootn) {
	if (!root && !rootn) return true;
	if (!root || !rootn) return false;
	if (root->val != rootn->val) return false;
	if (!treeCmp(root->left, rootn->left)) return false;
	if (!treeCmp(root->right, rootn->right)) return false;
	return true;
}

void deleteTree(node* root) {
	if (root->left) deleteTree(root->left);
	if (root->right) deleteTree(root->right);
	if (root) free(root);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF && n != 0) {
		char list[20];
		scanf("%s", list);
		node* root = buildTree(list);
		for (int i = 0; i < n; i++) {
			char listn[20];
			scanf("%s", listn);
			node* rootn = buildTree(listn);
			if (treeCmp(root, rootn)) {
				printf("YES\n");
			}
			else printf("NO\n");
			deleteTree(rootn);
		}
		deleteTree(root);
	}
	return 0;
}