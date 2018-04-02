#include<iostream>
#include<memory.h>

using namespace std;

<<<<<<< HEAD
int M, N;
int map[501][501];
int dp[501][501];
int way[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

int downroad(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return 0;
=======
int mt[501][501];
int dp[501][501];
int M, N, cnt;
int way[4] = { -1, 0, 1, 0 };

int func(int y, int x)
{
	if (y < 0 || y >= M || x < 0 || x >= N)
		return 0;

>>>>>>> d9b35b1a9176f37188b0cc3ba172da378808a60d
	if (y == M - 1 && x == N - 1)
		return 1;

	int &ret = dp[y][x];

	if (ret != -1)
		return ret;
<<<<<<< HEAD
	ret = 0;
	for (int i = 0; i < 4; i++)
		if(map[y][x] > map[y + way[i][0]][x + way[i][1]])
			ret += downroad(y + way[i][0], x + way[i][1]);
=======

	ret = 0;

	for (int i = 0; i < 4; i++) {
		int nY = y + way[i], nX = x + way[(i + 3) % 4];
		if (mt[y][x] > mt[nY][nX])
			ret += func(nY, nX);
	}
>>>>>>> d9b35b1a9176f37188b0cc3ba172da378808a60d
	return ret;
}

int main()
{
	scanf("%d %d", &M, &N);

<<<<<<< HEAD
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", downroad(0, 0));
=======
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &mt[i][j]);

	printf("%d", func(0, 0));
>>>>>>> d9b35b1a9176f37188b0cc3ba172da378808a60d
	return 0;
}