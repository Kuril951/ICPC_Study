#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>

#define pii pair<int, int>	// first : small, second : big

using namespace std;

int N, M;
int num[100001];

pii getMaxMin(pii a, pii b)
{
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}

pii init(vector<pii> &tree, int node, int nodeL, int nodeR)
{
	if (nodeL == nodeR) {
		return tree[node] = make_pair(num[nodeL], num[nodeL]);
	}
	int mid = (nodeL + nodeR) / 2;
	tree[node] = getMaxMin(init(tree, node * 2, nodeL, mid), init(tree, node * 2 + 1, mid + 1, nodeR));
	return tree[node];
}

pii findMaxMin(vector<pii> &tree, int node, int nodeL, int nodeR, int L, int R)
{
	if (R < nodeL || nodeR < L) return make_pair(INT_MAX, INT_MIN);
	if (L <= nodeL && nodeR <= R) return tree[node];
	int mid = (nodeL + nodeR) / 2;
	return getMaxMin(findMaxMin(tree, node * 2, nodeL, mid, L, R),
		findMaxMin(tree, node * 2 + 1, mid + 1, nodeR, L, R));
}

int main()
{
	scanf("%d %d", &N, &M);
	int h = (int)ceil(log2(N));
	vector<pii> tree(1 << (h + 1));

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	init(tree, 1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pii ans = findMaxMin(tree, 1, 0, N - 1, a - 1, b - 1);
		printf("%d %d\n", ans.first, ans.second);
	}

	return 0;
}