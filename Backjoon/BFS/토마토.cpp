#include<iostream>
#include<queue>

using namespace std;

int tomato[1001][1001];
int num[4] = { -1, 0, 1, 0 };
int N, M;

bool isInBound(int y, int x)
{
	if (y < 0 || y >= N || x < 0 || x >= M)
		return false;
	return true;
}

int main()
{
	queue<pair<int, int>> Q;

	scanf("%d %d", &M, &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1)
				Q.push(make_pair(i, j));
		}
	int time = 0;
	queue<pair<int, int>> Qtmp;

	while (!Q.empty()) {
		while(!Q.empty()) {
			Qtmp.push(Q.front());
			Q.pop();
		}
		while (!Qtmp.empty()) {
			auto cur = Qtmp.front();
			int y = cur.first, x = cur.second;

			Qtmp.pop();
			for (int i = 0; i < 4; i++) {
				int nextY = y + num[i], nextX = x + num[(i + 3) % 4];
				if (isInBound(nextY, nextX) && !tomato[nextY][nextX]) {
					tomato[nextY][nextX] = 1;
					Q.push(make_pair(nextY, nextX));
				}
			}
		}
		time++;
	}

	for(int i =0; i<N; i++)
		for(int j=0; j<M; j++)
			if (tomato[i][j] == 0) {
				printf("-1");
				return 0;
			}
	printf("%d", time - 1);

	return 0;
}