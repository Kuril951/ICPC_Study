#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int T, n;
int num[101][101];
int dp[101][101];

int func(int x, int y)
{
	if (y == n - 1)
		return num[y][x];

	int &ret = dp[y][x];

	if (ret)
		return ret;

	return ret = max(func(x, y + 1), func(x + 1, y + 1)) + num[y][x];
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		memset(dp, 0, sizeof(dp));

		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < i + 1; j++)
				scanf("%d", &num[i][j]);
		printf("%d\n", func(0, 0));
	}


	return 0;
}