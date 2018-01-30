#include <iostream>
#include <algorithm>

using namespace std;

int tree_node[2 << 22];
int sum[2 << 22];
int n;

int dfs(int idx, int level)
{
	if (level == n)
		return sum[idx] = tree_node[idx];
	return sum[idx] = max(dfs(2 * idx, level + 1), dfs(2 * idx + 1, level + 1)) + tree_node[idx];
}

void dfs2(int idx, int level, int max)
{
	if (level == n) {
		tree_node[idx] = max;
		return;
	}
	if (max == 0)
		return;

	int add;
	if (sum[2 * idx] > sum[2 * idx + 1])
		add = max - sum[2 * idx];
	else
		add = max - sum[2 * idx + 1];

	tree_node[idx] = add;

	dfs2(2 * idx, level + 1, max - add);
	dfs2(2 * idx + 1, level + 1, max - add);
}

int main()
{

	cin >> n;

	for (int i = 0; i < ((1 << (n + 1)) - 2); i++ )
		scanf("%d",&tree_node[i  + 2]);

	dfs(1, 0);
	dfs2(1, 0, sum[1]);

	int a=0;

	for (int i = 0; i < ((2 << (n + 1)) - 2); i++)
		a += tree_node[i + 2];

	cout << a;

	return 0;
}
