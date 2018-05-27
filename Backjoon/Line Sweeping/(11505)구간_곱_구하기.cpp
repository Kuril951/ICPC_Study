#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define MOD 1000000007
#define ll long long

using namespace std;

ll init(vector<ll> &num, vector<ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = num[start];
	else
		return tree[node] = (init(num, tree, node * 2, start, (start + end) / 2) \
			* init(num, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

ll product(vector<ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return (product(tree, node * 2, start, mid, left, right) \
		* product(tree, node * 2 + 1, mid + 1, end, left, right)) % MOD;
}

ll update(vector<ll> &tree, int node, int start, int end, int value, int idx)
{
	if (idx < start || end < idx)
		return tree[node];
	if (start == end)
		return tree[node] = value;
	if (start != end) {
		return tree[node] = (update(tree, node * 2, start, (start + end) / 2, value, idx)
			* update(tree, node * 2 + 1, (start + end) / 2 + 1, end, value, idx)) % MOD;
	}
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	vector<ll> num(N);
	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));
	vector<ll> tree(tree_size, 1);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	init(num, tree, 1, 0, N - 1);

	for (int i = 0; i < M + K; i++)
	{
		int sig, a, b;

		scanf("%d %d %d", &sig, &a, &b);

		if (sig == 1) {
			update(tree, 1, 0, N - 1, b, a - 1);
			num[a - 1] = b;
		}
		else {
			printf("%lld\n", product(tree, 1, 0, N - 1, a - 1, b - 1));
		}
	}

	return 0;
}