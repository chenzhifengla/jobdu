#include <stdio.h>
#include <stdlib.h>
struct node {
	node* left;
	node* right;
	int val;
};

node* insertNode(node* root, node* thisnode) {
	if (!root) root = thisnode;
	else if (thisnode->val < root->val) {
		root->left = insertNode(root->left, thisnode);
	}
	else if (thisnode->val > root->val) {
		root->right = insertNode(root->right, thisnode);
	}
	return root;
}

void preOrderReverse(node* root) {
	printf("%d ", root->val);
	if (root->left) preOrderReverse(root->left);
	if (root->right) preOrderReverse(root->right);
}

void inOrderReverse(node* root) {
	if (root->left) inOrderReverse(root->left);
	printf("%d ", root->val);
	if (root->right) inOrderReverse(root->right);
}

void postOrderReverse(node* root) {
	if (root->left) postOrderReverse(root->left);
	if (root->right) postOrderReverse(root->right);
	printf("%d ", root->val);
}

void deleteTree(node* root) {
	if (root->left) deleteTree(root->left);
	if (root->right) deleteTree(root->right);
	free(root);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		node* root = NULL;
		for (int i = 0; i < n; i++) {
			node* thisnode = (node*)malloc(sizeof(node));
			thisnode->left = thisnode->right = NULL;
			scanf("%d", &thisnode->val);
			root = insertNode(root, thisnode);
		}
		preOrderReverse(root);
		printf("\n");
		inOrderReverse(root);
		printf("\n");
		postOrderReverse(root);
		printf("\n");
		deleteTree(root);
	}
	return 0;
}