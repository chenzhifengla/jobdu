/*
#include<stdio.h>
#include<stdlib.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};
int buf[10000][13][32];
struct date {
	int day;
	int month;
	int year;
	void nextDay() {
		day++;
		if (day > dayOfMonth[month][ISYEAP(year)]) {
			month++;
			day = 1;
			if (month > 12) {
				year++;
				month = 1;
			}
		}
	}
};
int main() {
	date dtemp;
	dtemp.day = dtemp.month = 1;
	dtemp.year = 0;
	int day = 0;
	while (dtemp.year < 10001) {
		buf[dtemp.year][dtemp.month][dtemp.day] = day;
		dtemp.nextDay();
		day++;
	}
	int y, m, d;
	int y2, m2, d2;
	while (scanf("%4d%2d%2d", &y, &m, &d) != EOF) {
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		printf("%d\n", abs(buf[y][m][d] - buf[y2][m2][d2]) + 1);
	}
	return 0;
}
*/



#include <iostream>
//#include <stdio.h>
using namespace std;

inline int  ISYEAP(int x) { return ((x % 100 != 0 && x % 4 == 0 || x % 400 == 0) ? 1 : 0); }

int dayOfMonth[13][2] = {
	0, 0,
	31, 31,
	28, 29,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31,
	31, 31,
	30, 30,
	31, 31,
	30, 30,
	31, 31
};

class Date {
public:
	int year;
	int month;
	int day;

	void NextDay() {
		++day;
		if (day > dayOfMonth[month][ISYEAP(year)]) {
			day = 1;
			++month;
			if (month > 12) {
				month = 1;
				++year;
			}
		}
	}
};

int buf[5000][13][32];

int Abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	Date MyDate;
	int count = 0;
	MyDate.year = 0;
	MyDate.month = 1;
	MyDate.day = 1;
	while (MyDate.year != 5001) {
		buf[MyDate.year][MyDate.month][MyDate.day] = count;
		MyDate.NextDay();
		++count;
	}
	int y1, m1, d1;
	int y2, m2, d2;
	while (scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF) {
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		int num = Abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1;
		cout << num << endl;
	}
	return 0;
}