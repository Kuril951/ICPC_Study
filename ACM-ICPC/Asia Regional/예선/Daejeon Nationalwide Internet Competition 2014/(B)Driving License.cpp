#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>

#define MAX_N 101
#define MAX_ROTATE 201
#define WAY 2
#define INF 999999999

using namespace std;

int M, N, L, G;
int dp[MAX_N][MAX_N][MAX_ROTATE][WAY]; // 최소 연료 사용량
int cmap[MAX_N][MAX_N];
int rmap[MAX_N][MAX_N];

int drive(int y, int x, int rotateCnt, int way)
{
	if (rotateCnt == -1)
		return INF;
	if (y == M - 1 && x == N - 1)
		return 0;

	int &ret = dp[y][x][rotateCnt][way];
	if (ret != INT_MAX)
		return ret;

	ret = INF;
	if (way) {
		if (y + 1 < M)
			ret = drive(y + 1, x, rotateCnt, way) + rmap[y + 1][x];
		if (x + 1 < N)
			ret = min(ret, drive(y, x + 1, rotateCnt - 1, !way) + cmap[y][x + 1]);
	}
	else {
		if (y + 1 < M)
			ret = drive(y + 1, x, rotateCnt - 1, !way) + rmap[y + 1][x];
		if (x + 1 < N)
			ret = min(ret, drive(y, x + 1, rotateCnt, way) + cmap[y][x + 1]);
	}

	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++)
				for (int k = 0; k < MAX_ROTATE; k++)
					for (int l = 0; l < WAY; l++)
						dp[i][j][k][l] = INT_MAX;

		scanf("%d %d %d %d", &M, &N, &L, &G);
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N - 1; j++)
				scanf("%d", &cmap[i][j + 1]);
		for (int i = 0; i < M - 1; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &rmap[i + 1][j]);

		int res = -1;
		for (int i = 1; i < N + M; i++) {
			int tmp = min(drive(0, 0, i, 0), drive(0, 0, i, 1));
			if (tmp <= G) {
				res = (N + M - 2) * L + i;
				break;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}