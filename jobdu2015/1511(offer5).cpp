#include <stdio.h>
struct node {
	int value;
	node* next;
};

void delList(node* pHead) {
	while (pHead != NULL) {
		node* pDel = pHead;
		pHead = pHead->next;
		delete pDel;
	}
}

int main() {
	int n;
	node* pHead = new node;
	pHead->next = NULL;
	scanf("%d", &n);
	while (n > 0) {
		node* pNew = new node;
		pNew->value = n;
		if (pHead->next == NULL) {
			pNew->next = NULL;
		}
		else {
			pNew->next = pHead->next;
		}
		pHead->next = pNew;
		scanf("%d", &n);
	}
	for (node* p = pHead->next; p; p = p->next) {
		printf("%d\n", p->value);
	}
	delList(pHead); 
	return 0;
}