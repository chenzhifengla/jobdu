#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	//string����ԭ�����ַ�����
	string str;
	cin >> n;
	cin >> str;
	vector<int> other;
	//other��̬���鱣������޸�λ����ĸ�����
	int max = str[n - 1] - '0';
	other.push_back(max);
	for (int i = n - 2; i >= 0; i--) {
		//��������ַ�����
		int thisnum = str[i] - '0';
		//�����ǰλ�ַ��ȳ��ֹ��Ķ��󣬾ͱ�����other��̬�����в�����max
		if (thisnum > max) {
			max = thisnum;
			other.push_back(max);
		}
		//�����ǰλ��������ô��Ҫ���ѱ����other��̬������Ѱ��һλ���ڵ�ǰ�ַ�����С�ַ�
		else {
			//������other����
			sort(other.begin(), other.end());
			//�ٱ���other����
			for (int j = 0; j < other.size(); j++) {
				//�����������ַ���str���鵱ǰλ���ʱ�򽻻�other�����д��ַ���str�ж�Ӧ�ַ�
				if (other[j] > thisnum) {
					str[i] = other[j] + '0';
					other[j] = thisnum;
					break;
				}
			}
			break;
		}
	}
	//�����ܴ����������λ��ȷ�������������漸λ����С����Ϊother�����Ѿ���������ֱ�ӱ�������str�м���
	int size = other.size();
	for (int i = 0; i < size; i++) {
		str[n - size + i] = other[i] + '0';
	}
	cout << str << endl;
	return 0;
}