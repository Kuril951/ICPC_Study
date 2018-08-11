#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

#define ll long long

using namespace std;


const ll MAX_N = 1 << 21;
int N, M, K;
ll lazy[MAX_N];
vector<ll> tree(1 << (int)ceil(log2(MAX_N) + 1));

void propgation(int node, int nL, int nR)
{
	// lazy 값이 있으면 실행
	if (lazy[node]) {
		// 리프노드가 아니면 실행
		if (nL < nR) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		tree[node] += lazy[node] * (nR - nL + 1);
		lazy[node] = 0;
	}
}

void add(int node, int nL, int nR, int s, int e, int num)
{
	propgation(node, nL, nR);

	if (e < nL || nR < s) return;
	if (s <= nL && nR <= e) {
		lazy[node] += num;
		propgation(node, nL, nR);
		return;
	}
	if (nL != nR) {
		int mid = (nL + nR) / 2;
		add(node * 2, nL, mid, s, e, num);
		add(node * 2 + 1, mid + 1, nR, s, e, num);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

ll sum(int node, int nL, int nR, int s, int e)
{
	propgation(node, nL, nR);
	if (e < nL || nR < s) return 0;
	if (s <= nL && nR <= e) return tree[node];
	int mid = (nL + nR) / 2;
	return sum(node * 2, nL, mid, s, e) + sum(node * 2 + 1, mid + 1, nR, s, e);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		add(1, 0, N - 1, i, i, tmp);
	}

	for (int i = 0; i < M + K; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c, d;
			scanf("%d %d %d", &b, &c, &d);
			add(1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 0, N - 1, b - 1, c - 1));
		}
	}

	return 0;
}