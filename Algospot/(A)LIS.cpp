#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int N;
int num[501];
int dp[501];

int func(int idx)
{
	if (idx == N - 1)
		return 1;

	int &ret = dp[idx];

	if (ret)
		return ret;
	ret = 1;
	for (int i = idx + 1; i < N; i++) {
		int tmp = func(i) + 1;
		if (num[idx] < num[i])
			ret = max(ret, tmp);
	}

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &num[i]);
		func(0);
		int res = 0;
		for (int i = 0; i < N; i++)
			res = max(res, dp[i]);
		printf("%d\n", res);
	}

	return 0;
}