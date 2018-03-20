#include<iostream>
#include<memory.h>

using namespace std;

int mt[501][501];
int dp[501][501];
int M, N, cnt;
int way[4] = { -1, 0, 1, 0 };

int func(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return 0;

	if (y == M - 1 && x == N - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nY = y + way[i], nX = x + way[(i + 3) % 4];
		if (mt[y][x] > mt[nY][nX])
			ret += func(nY, nX);
	}
	return ret;
}

int main()
{
	scanf("%d %d", &M, &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &mt[i][j]);

	printf("%d", func(0, 0));
	return 0;
}