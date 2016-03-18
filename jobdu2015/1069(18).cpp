#define _CRT_SECURE_NO_WARNINGS
/*
//循环线性查找法
#include<stdio.h>
#include<string.h>

struct student {
	char num[100];
	char name[200];
	char sex[5];
	int age;
}stu[2000];


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%d", stu[i].num, stu[i].name, stu[i].sex, &stu[i].age);
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			char num[100];
			scanf("%s", num);
			int ans = -1;
			for (int j = 0; j < n; j++) {
				if (strcmp(stu[j].num, num) == 0) {
					ans = j;
					break;
				}
			}
			if (ans != -1) {
				printf("%s %s %s %d\n", stu[ans].num, stu[ans].name,
					stu[ans].sex, stu[ans].age);
			}
			else {
				printf("No Answer!\n");
			}
		}
	}
	return 0;
}

*/

//排序后二分查找法
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct Student {
	char num[100];
	char name[100];
	int age;
	char sex[5];
	bool operator < (const Student &A) const {
		return strcmp(num, A.num) < 0;
	}
}stu[1001];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s%s%s%d", stu[i].num, stu[i].name, stu[i].sex, &stu[i].age);
		}
		sort(stu, stu + n);
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			char num[100];
			scanf("%s", num);
			int ans = -1;
			int top = n - 1, base = 0;
			while (top >= base) {
				int mid = (top + base) / 2;
				int tmp = strcmp(stu[mid].num, num);
				if (tmp == 0) {
					ans = mid;
					break;
				}
				else if (tmp > 0) top = mid - 1;
				else base = mid + 1;
			}
			if (ans != -1) {
				printf("%s %s %s %d\n", stu[ans].num, stu[ans].name,
					stu[ans].sex, stu[ans].age);
			}
			else {
				printf("No Answer!\n");
			}
		}
	}
	return 0;
}