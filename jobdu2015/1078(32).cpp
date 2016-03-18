#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
	node* left;
	node* right;
	char c;
};
char pre[30], in[30];

node* buildTree(int prestart, int preend, int instart, int inend) {
	node* root = (node*)malloc(sizeof(node));
	root->c = pre[prestart];
	int index;
	for (index = instart; index <= inend; index++) {
		if (in[index] == root->c) break;
	}
	int leftlen = index - instart;
	int rightlen = inend - index;
	if (leftlen > 0) {
		root->left = buildTree(prestart + 1, prestart + leftlen, instart, index - 1);
	}
	else root->left = NULL;
	if (rightlen > 0) {
		root->right = buildTree(preend - rightlen + 1, preend, index + 1, inend);
	}
	else root->right = NULL;
	return root;
}

void postOrderReverse(node* root) {
	if (root->left) postOrderReverse(root->left);
	if (root->right) postOrderReverse(root->right);
	printf("%c", root->c);
}

void deleteTree(node* root) {
	if (root->left) deleteTree(root->left);
	if (root->right) deleteTree(root->right);
	free(root);
}


int main() {
	while (scanf("%s%s", pre, in) != EOF) {
		int prelen = strlen(pre);
		int inlen = strlen(in);
		node* root = buildTree(0, prelen - 1, 0, inlen - 1);
		postOrderReverse(root);
		printf("\n");
		deleteTree(root);
	}
	return 0;
}