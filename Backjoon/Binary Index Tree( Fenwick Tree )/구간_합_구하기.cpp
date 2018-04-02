#include<iostream>

#define ll long long

using namespace std;

int N, M, K;
ll tree[1000001];		// BIT Tree
ll number[1000001];		// 원본 숫자

void update(int i, ll num)
{
	while (i <= N) {
		tree[i] += num;
		i += (i & -i);
	}
}

ll sum(int i) 
{
	ll ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &number[i]);
		update(i, number[i]);
	}

	for (int i = 0; i < M + K; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			ll c;
			scanf("%d %lld", &b, &c);
			// 원래 숫자 number에서 변하는 값만큼 세그먼트 트리 업데이트
			update(b, c - number[b]);
			number[b] = c;
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}

	return 0;
}