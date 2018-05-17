#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>

using namespace std;

int N, book[1000];
int dp[1000][1000];

int func(int s, int e)
{
	if (s + 1 == e)
		return 0;

	int &ret = dp[s][e];
	if (ret)
		return ret;
	ret = INT_MAX;

	int sum = 0;
	for (int i = s; i < e; i++)
		sum += book[i];
	for (int i = s + 1; i < e; i++)
		ret = min(ret, func(s, i) + func(i, e) + sum);

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
			scanf("%d", &book[i]);

		printf("%d\n", func(0, N));
	}

	return 0;
}