#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int file[501];
int dp[501][501];

int merge_file(int s, int e)
{
	if (s == e)
		return 0;

	int &ret = dp[s][e];

	if (ret != 0)
		return ret;

	ret += 999999999;
	int sum = 0;

	for (int i = s; i <= e ; i++)
		sum += file[i];

	for (int i = s; i < e; i++)
		ret = min((merge_file(s, i) + merge_file(i + 1, e)) + sum, ret);

	return ret;
}

int main()
{
	int T, K;

	scanf("%d", &T);

	while (T--)
	{
		int sum = 0;
		scanf("%d", &K);

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < K; i++)
			scanf("%d", &file[i]);

		printf("%d\n", merge_file(0,K-1));
	}

	return 0;
}
