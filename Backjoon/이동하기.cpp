#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int N, M;
int maze[1001][1001];
int dp[1001][1001];

int func(int x, int y)
{
	if (x >= M || y >= N)
		return 0;
	if (x == M - 1 && y == N - 1)
		return maze[y][x];

	int &ret = dp[y][x];
	if (ret != -1)
		return ret;

	return ret = (max(max(func(x + 1, y), func(x, y + 1)), func(x + 1, y + 1)) + maze[y][x]);
}

int main()
{
	scanf("%d %d", &N, &M);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &maze[i][j]);

	printf("%d", func(0, 0));

	return 0;
}