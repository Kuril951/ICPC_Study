#include<iostream>
#include<vector>
#include<cmath>

#define ll long long

using namespace std;

int N, M, k;
ll num[1000001];
vector<ll> tree(1 << ((int)ceil(log2(1000000)) + 1));

ll init(int node, int nodeL, int nodeR)
{
	if (nodeL == nodeR)
		return tree[node] = num[nodeL];
	else {
		return tree[node] = init(node * 2, nodeL, (nodeL + nodeR) / 2) +
			init(node * 2 + 1, (nodeL + nodeR) / 2 + 1, nodeR);
	}
}

void update(int node, int nodeL, int nodeR, int idx, ll diff)
{
	if (idx < nodeL || idx > nodeR) return;
	tree[node] = tree[node] + diff;
	if (nodeL != nodeR) {
		update(node * 2, nodeL, (nodeL + nodeR) / 2, idx, diff);
		update(node * 2 + 1, (nodeL + nodeR) / 2 + 1, nodeR, idx, diff);
	}
}

ll sum(ll node, int nodeL, int nodeR, int L, int R)
{
	if (R < nodeL || nodeR < L) return 0;
	if (L <= nodeL && nodeR <= R) return tree[node];
	return sum(node * 2, nodeL, (nodeL + nodeR) / 2, L, R) +
		sum(node * 2 + 1, (nodeL + nodeR) / 2 + 1, nodeR, L, R);
}

int main()
{
	scanf("%d %d %d", &N, &M, &k);
	for (int i = 0; i < N; i++)
		scanf("%lld", &num[i]);

	init(1, 0, N - 1);
	for (int i = 0; i < M + k; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			ll c;
			scanf("%d %lld", &b, &c);
			ll diff = c - num[b - 1];
			num[b - 1] = c;
			update(1, 0, N - 1, b - 1, diff);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
		}
	 }

	return 0;
}