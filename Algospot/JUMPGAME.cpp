#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
int map[101][101];
int dp[101][101];

int func(int x, int y)
{
	if (x >= n || y >= n)
		return -1;
	if (x == n - 1 && y == n - 1)
		return 1;

	int &ret = dp[y][x];	// -1 길없음 1 길 찾음
	
	if (ret == 1) return 1;
	if (ret == -1) return -1;

	return ret = max(func(x + map[y][x], y), func(x, y + map[y][x]));
}


int main()
{
	int T;

	scanf("%d", &T);
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		if (func(0, 0) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}


	return 0;
}