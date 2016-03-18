#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct student {
	int num;
	char name[9];
	int grade;
}stu[100001];

bool cmp_num(student a, student b) {
	return a.num < b.num;
}

bool cmp_name(student a, student b) {
	int tmp = strcmp(a.name, b.name);
	if (tmp == 0) return a.num < b.num;
	else return tmp < 0;
}

bool cmp_grade(student a, student b) {
	if (a.grade == b.grade) return a.num < b.num;
	else return a.grade < b.grade;
}

int main()
{
	int n, c, m;
	m = 0;
	while (scanf("%d%d", &n, &c) != EOF) {
		if (n == 0) break;
		m++;
		for (int i = 0; i < n; i++) {
			scanf("%d%s%d", &stu[i].num, stu[i].name, &stu[i].grade);
		}
		switch (c) {
		case 1:sort(stu, stu + n, cmp_num); break;
		case 2:sort(stu, stu + n, cmp_name); break;
		case 3:sort(stu, stu + n, cmp_grade);
		}
		printf("Case %d:\n", m);
		for (int i = 0; i < n; i++) {
			printf("%06d %s %d\n", stu[i].num, stu[i].name, stu[i].grade);
		}
	}
	return 0;
}