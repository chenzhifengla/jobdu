#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
struct bigInter {
	char num[200];
	int size;
	bigInter() {
		size = 0;
		memset(num, '0', 200);
	}
	bigInter operator * (const int &b) const {
		bigInter multi;
		int current = 0;
		for (int i = 0; i < size; i++) {
			int n = (num[i] - '0') * b + current;
			multi.num[i] = n % 10 + '0';
			current = n / 10;
		}
		multi.size = size;
		while (current > 0) {
			multi.num[multi.size++] = current % 10 + '0';
			current /= 10;
		}
		return multi;
	}
	bigInter operator + (const bigInter &b) const {
		bigInter plus;
		int current = 0;
		plus.size = size > b.size ? size : b.size;
		for (int i = 0; i < plus.size; i++) {
			int n = num[i] - '0' + b.num[i] - '0' + current;
			plus.num[i] = n % 10 + '0';
			current = n / 10;
		}
		while (current > 0) {
			plus.num[plus.size++] = current % 10 + '0';
			current /= 10;
		}
		return plus;
	}
	bool operator > (const bigInter &b) const {
		if (size != b.size) return size > b.size;
		for (int i = 0; i < size; i++) {
			if (num[i] != b.num[i]) return num[i] > b.num[i];
		}
		return true;
	}
};
struct E {
	int next;
	bigInter length;
};
vector<E> v[101];

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; i++) v[i].clear();
		bigInter k;
		k.size = 1;
		k.num[0] = '1';
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			E temp;
			temp.length = k;
			temp.next = b;
			v[a].push_back(temp);
			temp.next = a;
			v[b].push_back(temp);
			k = k * 2;
		}
		bool mark[101];
		bigInter len[101];
		for (int i = 0; i < n; i++) {
			mark[i] = false;
			len[i].size = 0;
		}
		int newP = 0;
		mark[0] = true;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < v[newP].size(); j++) {
				int t = v[newP][j].next;
				if (mark[t]) continue;
				bigInter length = v[newP][j].length;
				if (len[t].size == 0 || (len[t] > len[newP] + length)) {
					len[t] = len[newP] + length;
				}
			}
			bigInter min;
			min.size = 0;
			for (int j = 0; j < n; j++) {
				if (mark[j]) continue;
				if (len[j].size == 0) continue;
				if (min.size == 0 || min > len[j]) {
					min = len[j];
					newP = j;
				}
			}
			mark[newP] = true;
		}
		for (int i = 1; i < n; i++) {
			if (len[i].size == 0) {
				printf("-1\n");
			}
			else if (len[i].size <= 5) {
				for (int j = 0; j <= len[i].size; j++) {
					printf("%c", len[i].num[j]);
				}
				printf("\n");
			}
			else {
				for (int j = 0; j <= 5; j++) {
					printf("%c", len[i].num[j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}