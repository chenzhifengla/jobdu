/*
#include <stdio.h>
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int index = n - k;
		int num;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (i == index) {
				num = x;
			}
		}
		if (index >= 0 && index < n) {
			printf("%d\n", num);
		}
		else printf("NULL\n");
	}
	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
	int value;
	ListNode* next;
};
int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		ListNode* root = NULL;
		ListNode* pNow = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (!root){
				root = (ListNode*)malloc(sizeof(ListNode));
				root->value = x;
				root->next = NULL;
				pNow = root;
			}
			else {
				pNow->next = (ListNode*)malloc(sizeof(ListNode));
				pNow = pNow->next;
				pNow->value = x;
				pNow->next = NULL;
			}
		}
		int index = n - k;
		if (index < 0 || index >= n) {
			printf("NULL\n");
		}
		else {
			pNow = root;
			for (int i = 0; i < k; i++) {
				pNow = pNow->next;
			}
			ListNode* p = root;
			while (pNow) {
				p = p->next;
				pNow = pNow->next;
			}
			printf("%d\n", p->value);
		}
	}
	return 0;
}