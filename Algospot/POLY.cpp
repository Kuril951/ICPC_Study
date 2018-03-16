#include<iostream>
#include<memory.h>

#define MOD 10000000

using namespace std;

int N;
int dp[101][101];		// dp[i][j] -> i: 밑에 놓은 블럭 수, j: 남은 블럭수

int poly(int prevCnt, int blockCnt)
{
	if (blockCnt == 0)
		return 1;

	int &ret = dp[prevCnt][blockCnt];

	if (ret)
		return ret;

	for (int i = 1; i <= blockCnt; i++)
		ret = (ret + (poly(i, blockCnt - i) * (prevCnt + i - 1))) % MOD;

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while(T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);

		int res = 0;
		for (int i = 1; i <= N; i++)
			res = (res + poly(i, N - i)) % MOD;

		printf("%d\n", res);
	}

	return 0;
}