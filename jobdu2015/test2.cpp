#include <iostream>
using namespace std;
struct node {
	int value;
	node* next;
};
int main() {
	node** pHead = NULL;
	node* pNew = NULL;

	pNew = new node;
	pNew->value = 1;
	pNew->next = NULL;
	pHead = &pNew;

	pNew = new node;	//此时pHead变化?
	pNew->value = 2;
	pNew->next = *pHead;
	pHead = &pNew;


	return 0;
}