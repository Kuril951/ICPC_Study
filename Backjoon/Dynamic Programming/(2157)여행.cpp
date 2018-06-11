#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, M, K;
int dp[301][301];
int score[301][301];
vector<int> adj[301];

int func(int idx, int cnt)
{
	if (idx == N)
		return 0;
	if (cnt == M - 1)
		return -1;

	int &ret = dp[idx][cnt];
	if (ret != -1)
		return ret;
	ret = 0;

	for (auto i : adj[idx]) {
		int tmp;
		if ((tmp = func(i, cnt + 1)) == -1)
			continue;
		ret = max(ret, tmp + score[idx][i]);
	}
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < K; i++) {
		int a, b, c, flg = 0;
		scanf("%d %d %d", &a, &b, &c);
		if (a > b)
			continue;
		if (!score[a][b])
			adj[a].push_back(b);
		score[a][b] = max(score[a][b], c);
	}

	printf("%d", func(1, 0));

	return 0;
}