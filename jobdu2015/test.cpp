#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	//string保存原输入字符数组
	string str;
	cin >> n;
	cin >> str;
	vector<int> other;
	//other动态数组保存最大修改位后面的各个数
	int max = str[n - 1] - '0';
	other.push_back(max);
	for (int i = n - 2; i >= 0; i--) {
		//倒序遍历字符数组
		int thisnum = str[i] - '0';
		//如果当前位字符比出现过的都大，就保存在other动态数组中并更新max
		if (thisnum > max) {
			max = thisnum;
			other.push_back(max);
		}
		//如果当前位不够大，那么就要在已保存的other动态数组中寻找一位大于当前字符的最小字符
		else {
			//先排序other数组
			sort(other.begin(), other.end());
			//再遍历other数组
			for (int j = 0; j < other.size(); j++) {
				//当遍历到的字符比str数组当前位大的时候交换other数组中此字符与str中对应字符
				if (other[j] > thisnum) {
					str[i] = other[j] + '0';
					other[j] = thisnum;
					break;
				}
			}
			break;
		}
	}
	//现在能触碰到的最高位已确定，接下来后面几位尽量小，因为other数组已经排序，所以直接遍历放入str中即可
	int size = other.size();
	for (int i = 0; i < size; i++) {
		str[n - size + i] = other[i] + '0';
	}
	cout << str << endl;
	return 0;
}