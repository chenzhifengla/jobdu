#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct ListNode {
	int value;
	ListNode* next;
};
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		ListNode* root = NULL;
		ListNode* p = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (!root) {
				root = (ListNode*)malloc(sizeof(ListNode));
				root->value = x;
				root->next = NULL;
				p = root;
			}
			else {
				p->next = (ListNode*)malloc(sizeof(ListNode));
				p = p->next;
				p->value = x;
				p->next = NULL;
			}
		}
		ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
		pHead->next = NULL;
		for (p = root; p != NULL;) {
			ListNode* q = p->next;
			p->next = pHead->next;
			pHead->next = p;
			p = q;
		}
		if (n == 0) {
			printf("NULL\n");
		}
		else if (n == 1) {
			printf("%d\n", pHead->next->value);
		}
		else {
			p = pHead->next;
			printf("%d", p->value);
			for (p = p->next; p != NULL; p = p->next) {
				printf(" %d", p->value);
			}
			printf("\n");
		}
	}
	return 0;
}