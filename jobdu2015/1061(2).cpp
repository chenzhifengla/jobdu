#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<string.h>
struct student{
	char name[101];
	int age;
	int grade;
	bool operator < (const student &b) const {
		if (grade != b.grade) return grade < b.grade;
		int tmp = strcmp(name, b.name);
		if (tmp != 0) return tmp < 0;
		else return age < b.age;
	}
};
int main() {
	int n;
	student stu[1001];

	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%s%d%d", stu[i].name, &stu[i].age, &stu[i].grade);
		}
		std::sort(stu, stu + n);
		for (int i = 0; i < n; i++) {
			printf("%s %d %d\n", stu[i].name, stu[i].age, stu[i].grade);
		}
	}
	return 0;
}