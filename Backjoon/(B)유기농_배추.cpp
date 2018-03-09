#include<iostream>
#include<memory.h>

int M, N, K;
int field[52][52];

void dfs(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return;

	field[y][x] = 0;
	if (field[y - 1][x]) dfs(y - 1, x);
	if (field[y][x - 1]) dfs(y, x - 1);
	if (field[y + 1][x]) dfs(y + 1, x);
	if (field[y][x + 1]) dfs(y, x + 1);
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(field, 0, sizeof(field));
		scanf("%d %d %d", &M, &N, &K);

		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			field[y][x] = 1;
		}

		int cnt = 0;
		for(int i=0; i<N; i++)
			for (int j = 0; j < M; j++) {
				if (field[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}

		printf("%d\n", cnt);
	}

	return 0;
}