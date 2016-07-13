#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int value;
	Node* next;
};
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		Node* head1 = (Node*)malloc(sizeof(Node));
		Node* head2 = (Node*)malloc(sizeof(Node));
		Node* p = head1;
		head1->next = head2->next = NULL;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			p->next = (Node*)malloc(sizeof(Node));
			p = p->next;
			p->value = x;
			p->next = NULL;
		}
		p = head2;
		for (int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			p->next = (Node*)malloc(sizeof(Node));
			p = p->next;
			p->value = x;
			p->next = NULL;
		}

		Node* head3 = (Node*)malloc(sizeof(Node));
		head3->next = NULL;
		p = head1->next;
		Node* p2 = head2->next;
		Node* p3 = head3;
		while (p != NULL && p2 != NULL) {
			if (p->value < p2->value) {
				p3->next = p;
				p3 = p3->next;
				p = p->next;
			}
			else {
				p3->next = p2;
				p3 = p3->next;
				p2 = p2->next;
			}
		}
		if (p != NULL) {
			p3->next = p;
		}
		if (p2 != NULL) {
			p3->next = p2;
		}
		p = head3->next;
		if (p == NULL) {
			printf("NULL\n");
		}
		else {
			printf("%d", p->value);
			for (p = p->next; p != NULL; p = p->next) {
				printf(" %d", p->value);
			}
			printf("\n");
		}
	}
	return 0;
}