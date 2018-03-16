#include<iostream>

int board[15][15];
int N;

void fillBoard(int y, int x, int n) 
{
	for (int i = y; i < N; i++)
		board[i][x] += n;
	for (int i = 1; i < N - y; i++) {
		if(x + i < N)
			board[y + i][x + i] += n;
		if(x - i >= 0)
			board[y + i][x - i] += n;
	}
}

int dfs(int y, int x)
{
	if (y == N)
		return 1;
	int ret = 0;
	for (int i = 0; i < N; i++)
		if (!board[y][i]) {
			fillBoard(y, i, 1);
			ret += dfs(y + 1, i);
			fillBoard(y, i, -1);
		}
	return ret;
}

int main()
{
	scanf("%d", &N);

	printf("%d", dfs(0, 0));

	return 0;
}