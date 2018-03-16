#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int maze[102][102];
int dp[102][102];
int num[4] = { -1, 0, 1, 0 };

int func(int y, int x)
{
	if (y == N && x == M)
		return 1;
	
	int &ret = dp[y][x];

	if (ret)
		return ret;

	ret = 100000;
	maze[y][x] = 0;
	for (int i = 0; i < 4; i++)
		if(maze[y + num[i]][x + num[(i + 3) % 4]])
			ret = min(ret, func(y + num[i], x + num[(i + 3) % 4]));
	maze[y][x] = 1;

	return ++ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		getchar();
		for (int j = 1; j <= M; j++) {
			char ch;
			scanf("%c", &ch);
			maze[i][j] = ch - '0';
		}
	}

	printf("%d\n", func(1, 1));
	return 0;
}