/*ʹ��stl������
#include<stdio.h>
#include<algorithm>
int main() 
{
	int n;
	int buf[101];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		std::sort(buf, buf + n);
		for (int i = 0; i < n; i++)
			printf("%d ", buf[i]);
		printf("\n");
	}
	return 0;	
}
*/

/*ð�����򣬴�ѭ����0��n-1��Сѭ����0��n-i-1
#include<stdio.h>
int main()
{
	int n;
	int buf[101];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (buf[j] > buf[j + 1]) {
					int tmp = buf[j];
					buf[j] = buf[j + 1];
					buf[j + 1] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}
*/

//ѡ�����򣬴�ѭ����0��n-1��
#include<stdio.h>
int main()
{
	int n;
	int buf[101];
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &buf[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			int small = buf[i];
			int index = i;
			for (int j = i + 1; j < n; j++) {
				if (buf[j] < small) {
					small = buf[j];
					index = j;
				}
			}
			int tmp = buf[i];
			buf[i] = buf[index];
			buf[index] = tmp;
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", buf[i]);
		}
		printf("\n");
	}
	return 0;
}