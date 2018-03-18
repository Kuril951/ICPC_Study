#include<iostream>
#include<algorithm>

using namespace std;

int board[11][11], dR[21], dL[21];	//board: 체스판, dR, dL: 해당 부분에 놓을수 있는지
int N;

int dfs(int y, int x)
{
	if (y == N)
		return 0;

	int ret = 0;
	int nextX = x + 2 < N ? x + 2 : (x + 1) % 2;
	int nextY = x + 2 < N ? y : y + 1;
	
	if (board[y][x] && !dL[x + y] && !dR[x - y +N]) {
		dL[x + y] = dR[x - y + N] = 1;
		ret = dfs(nextY, nextX) + 1;
		dL[x + y] = dR[x - y + N] = 0;
	}
	ret = max(ret, dfs(nextY, nextX));

	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	printf("%d\n", dfs(0, 0) + dfs(0, 1));

	return 0;
}