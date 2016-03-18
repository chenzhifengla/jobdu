#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define ISYEAP(x) x % 100 != 0 && x % 4 == 0 || x % 400 == 0 ? 1 : 0
int dayOfMonth[13][2]{
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
struct Date {
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
int date[10000][13][32];
int m2m(char* s) {
	switch (*s) {
	case 'A': {
		s++;
		if (*s == 'u') return 8;
		else return 4;
	}
	case 'D': return 12;
	case 'F': {
		return 2;
	}
	case 'J': {
		s++;
		if (*s == 'a') return 1;
		else {
			s++;
			if (*s == 'n') return 6;
			else return 7;
		}
		return 1;
	}
	case 'M': {
		s += 2;
		if (*s == 'r') return 3;
		else return 5;
	}
	case 'N': return 11;
	case 'O': return 10;
	case 'S': return 9;
	}
}
char week2week[8][20] = {
	"",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
	"Sunday"
};
int main() {
	Date t;
	t.day = t.month = 1;
	t.year = 0;
	int day = 1;
	while (t.year < 10000) {
		date[t.year][t.month][t.day] = day;
		t.nextDay();
		day++;
	}
	int d, m, y;
	char month[20];
	while (scanf("%d%s%d", &d, month, &y) != EOF) {
		m = m2m(month);
		int diff = date[y][m][d] - date[2015][10][5];
		diff = diff % 7;
		diff = diff > 0 ? diff : (diff + 7);
		int week = diff + 1;
		printf("%s\n", week2week[week]);
	}
	return 0;
}