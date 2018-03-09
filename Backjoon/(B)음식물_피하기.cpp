#include<iostream>
#include<algorithm>

int N, M, K;
int trash[101][101];

int dfs(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return 0;

	trash[y][x] = 0;

	int ret = 1;
	if (trash[y - 1][x]) ret += dfs(y - 1, x);
	if (trash[y][x - 1]) ret += dfs(y, x - 1);
	if (trash[y + 1][x]) ret += dfs(y + 1, x);
	if (trash[y][x + 1]) ret += dfs(y, x + 1);

	return ret;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++)	{
		int x, y;
		scanf("%d %d", &y, &x);
		trash[y - 1][x - 1] = 1;
	}
	int maxTrash = 0;
	for(int i=0; i<N; i++)
		for (int j = 0; j < M; j++) {
			if (trash[i][j])
				maxTrash = std::max(maxTrash, dfs(i, j));
		}
	printf("%d", maxTrash);
	return 0;
}