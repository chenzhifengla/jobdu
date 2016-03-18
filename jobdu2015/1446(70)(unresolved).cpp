#include <stdio.h>

int findRoot(int tree[], int n) {
	if (tree[n] == -1) return n;
	else {
		return findRoot(tree, tree[n]);
	}
}

int main() {
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF) {
		int tree[26];
		for (int i = 0; i < 26; i++) tree[i] = -1;
		int flag[26] = { 0 };	//��ʾ�Ƿ��������
		int num[26];	//��ʾ���ڵ�����
		for (int i = 0; i < 26; i++) num[i] = 1;
		int wei[26];	//��ʾ���ڵ���weight
		for (int i = 0; i < 26; i++) wei[i] = 0;
		int relatedwei[26];	//��ʾÿ�����������˵���ϵweight
		for (int i = 0; i < 26; i++) relatedwei[i] = 0;
		for (int i = 0; i < n; i++) {
			char str1[5], str2[5];
			int weight;
			scanf("%s%s%d", str1, str2, &weight);
			int a, b;
			a = str1[0] - 'A';
			b = str2[0] - 'A';
			flag[a] = flag[b] = 1;
			relatedwei[a] += weight;
			relatedwei[b] += weight;
			int root1, root2;
			root1 = findRoot(tree, a);
			root2 = findRoot(tree, b);
			if (root1 != root2) {
				tree[root2] = root1;
				num[root1] += num[root2];
			}
			wei[root1] += weight;
		}
		int ans = 0;	//��ʾgang������,Ҳ������������
		int root[26];	//�洢�����ı��
		for (int i = 0; i < 26; i++) {
			if (flag[i] == 1 && tree[i] == -1 && num[i] > 2
				&& wei[i] > k) {
				//flag[i]==1��ʾ�������
				//tree[i]==-1��ʾ��һ��ĸ�
				//num[i]>2��ʾ��������3��
				//wei[i]>k��ʾ������weight����k
				root[ans++] = i;				
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++) {
			//�������еĸ���root[i]��ʾ�����
			int maxnum = -1;
			int index = -1;
			for (int j = 0; j < 26; j++) {
				if (flag[j] == 1 && findRoot(tree, j) == root[i]
					&& relatedwei[j] > maxnum) {
					maxnum = relatedwei[j];
					index = j;
				}
			}
			char c = index + 'A';
			printf("%c%c%c %d\n", c, c, c, num[root[i]]);
		}
	}
	return 0;
}