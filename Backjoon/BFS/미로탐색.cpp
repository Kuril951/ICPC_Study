#include<iostream>
#include<queue>

using namespace std;

int N, M;
int maze[101][101];
int num[4] = { -1, 0, 1, 0 };

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

	// bfs
	queue<pair<int, int>> Q;

	Q.push(make_pair(1, 1));

	while (!Q.empty())
	{
		auto next = Q.front();
		int y = next.first, x = next.second;
		Q.pop();

		if (y == N && x == M) break;
		
		for (int i = 0; i < 4; i++) {
			int nextY = y + num[i], nextX = x + num[(i + 3) % 4];
			if (maze[nextY][nextX] == 1) {
				Q.push(make_pair(nextY, nextX));
				maze[nextY][nextX] += maze[y][x];
			}
		}
		maze[y][x] = 0;
	}

	printf("%d\n", maze[N][M]);

	return 0;
}