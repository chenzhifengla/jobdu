//前面注释掉的是使用数组静态分配结点的方法，已AC
//后面未注释的是动态分配结点的方法，已AC

/*
#include <stdio.h>
struct node {
	int value;
	int left, right;
}tree[1001];
int loc;
int preOrder[1001], inOrder[1001];

int constructTree(int pS, int pE, int iS, int iE) {
	int root = loc++;
	tree[root].value = preOrder[pS];
	tree[root].left = tree[root].right = -1;

	int midle;
	for (midle = iS; midle <= iE; midle++) {
		if (inOrder[midle] == preOrder[pS]) {
			break;
		}
	}
	if (midle > iE) return -1;
	int leftLen = midle - iS;
	int rightLen = iE - midle;
	
	if (midle > iS) {
		tree[root].left = constructTree(pS + 1, pS + leftLen, iS, midle - 1);
		if (tree[root].left == -1) return -1;
	}

	if (midle < iE) {
		tree[root].right = constructTree(pS + leftLen + 1, pE, midle + 1, iE);
		if (tree[root].right == -1) return -1;
	}

	return root;
}

void postOrderTraverse(int root) {
	if (tree[root].left >= 0) postOrderTraverse(tree[root].left);
	if (tree[root].right >= 0) postOrderTraverse(tree[root].right);
	printf("%d ", tree[root].value);
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		loc = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &preOrder[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &inOrder[i]);
		}
		int preStart = 0, preEnd = n - 1;
		int inStart = 0, inEnd = n - 1;
		int root = constructTree(preStart, preEnd, inStart, inEnd);
		if (root < 0) printf("No\n");
		else {
			postOrderTraverse(root);
			printf("\n");
		}
	}
	return 0;
}
*/

#include <stdio.h>
struct node {
	int value;
	node* left;
	node* right;
};
int* preOrder;
int* inOrder;

node* constructTree(int pS, int pE, int iS, int iE) {
	node* root = new node;
	root->value = preOrder[pS];
	root->left = root->right = NULL;

	int midle;
	for (midle = iS; midle <= iE; midle++) {
		if (preOrder[pS] == inOrder[midle]) {
			break;
		}
	}
	if (midle > iE) return NULL;

	int leftLen = midle - iS;
	int rightLen = iE - midle;
	if (midle != iS) {
		root->left = constructTree(pS + 1, pS + leftLen, iS, midle - 1);
		if (root->left == NULL) return NULL;
	}
	if (midle != iE) {
		root->right = constructTree(pS + leftLen + 1, pE, midle + 1, iE);
		if (root->right == NULL) return NULL;
	}

	return root;
}

void postOrderTraverse(node* root) {
	if (root->left) postOrderTraverse(root->left);
	if (root->right) postOrderTraverse(root->right);
	printf("%d ", root->value);
}

void destoryTree(node* root) {
	if (root->left) destoryTree(root->left);
	if (root->right) destoryTree(root->right);
	delete root;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		preOrder = new int[n];
		inOrder = new int[n];

		for (int i = 0; i < n; i++) {
			scanf("%d", &preOrder[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &inOrder[i]);
		}

		node* root;
		root = constructTree(0, n - 1, 0, n - 1);
		if (root) {
			postOrderTraverse(root);
		}
		else {
			printf("No");
		}
		printf("\n");
		if (root) destoryTree(root);
	}
	return 0;
}