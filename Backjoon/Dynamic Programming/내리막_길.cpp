#include<iostream>
#include<memory.h>

using namespace std;

int M, N;
int map[501][501];
int dp[501][501];
int way[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int downroad(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return 0;
	if (y == M - 1 && x == N - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < 4; i++)
		if(map[y][x] > map[y + way[i][0]][x + way[i][1]])
			ret += downroad(y + way[i][0], x + way[i][1]);
	return ret;
}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", downroad(0, 0));
	return 0;
}