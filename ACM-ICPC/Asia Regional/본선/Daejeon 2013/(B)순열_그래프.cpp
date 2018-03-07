#include<iostream>
#include<memory.h>

#define MAX_V 1000001
#define lld long long

using namespace std;

int A[MAX_V], B[MAX_V];		// A[i]: i번째 값, B[A[i]]: A[i]가 위치한 값
int tree[MAX_V];			// 펜윅 트리 -> 각각의 합을 저장
int N;

lld sum(lld i)
{
	lld ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= i & -i;
	}
	return ans;
}

void update(lld i)
{
	if (i == 0)
		return;
	while (i < N) {
		tree[i]++;
		i += (i & -i);
	}
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(tree, 0, sizeof(tree));

		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%lld", &A[i]);
		for (int i = 0; i < N; i++) {
			lld tmp;
			scanf("%lld", &tmp);
			B[tmp] = i;
		}

		lld res = 0;
		for (int i = 0; i < N; i++) {
			lld idx = B[A[i]];
			res += (idx - sum(idx));
			update(idx + 1);
		}

		printf("%lld\n",res);
	}


	return 0;
}