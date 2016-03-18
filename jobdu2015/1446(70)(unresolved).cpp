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
		int flag[26] = { 0 };	//表示是否有这个人
		int num[26];	//表示组内的人数
		for (int i = 0; i < 26; i++) num[i] = 1;
		int wei[26];	//表示组内的总weight
		for (int i = 0; i < 26; i++) wei[i] = 0;
		int relatedwei[26];	//表示每个人与其他人的联系weight
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
		int ans = 0;	//表示gang的数量,也是树根的数量
		int root[26];	//存储树根的编号
		for (int i = 0; i < 26; i++) {
			if (flag[i] == 1 && tree[i] == -1 && num[i] > 2
				&& wei[i] > k) {
				//flag[i]==1表示有这个人
				//tree[i]==-1表示是一组的根
				//num[i]>2表示组内至少3人
				//wei[i]>k表示组内总weight大于k
				root[ans++] = i;				
			}
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++) {
			//遍历所有的根，root[i]表示根编号
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