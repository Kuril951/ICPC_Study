#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int num[100001];
int tree[1<<18];
int N, M;

int update(int idx, int left, int right)
{
	if (left == right) {
		return tree[idx] = num[left];
	}
	int ret = update(2 * idx, left, (left + right) / 2);
	return tree[idx] = min(ret, update(2 * idx + 1, (left + right) / 2 + 1, right));
}

int treeMin(int idx, int left, int right, int s, int e)
{
	if (e < left || right < s)
		return INT_MAX;
	if (s <= left && right <= e)
		return tree[idx];
	int ret = treeMin(2 * idx, left, (left + right) / 2, s, e);
	ret = min(ret, treeMin(2 * idx + 1, (left + right) / 2 + 1, right, s, e));
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &num[i]);
	}
	tree[1] = update(1, 1, N);
	for (int i = 0; i < M; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%d\n", treeMin(1, 1, N, s, e));
	}
	return 0;
}