#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>

#define INF 100000000
#define MAX_V 11

using namespace std;

int N, city[MAX_V][MAX_V];
int dp[MAX_V][1 << MAX_V];

int func(int cur, int start, int state)
{
	if (state == (1 << N) - 1) {
		if (city[cur][start])
			return city[cur][start];
		return INF;
	}

	int &ret = dp[cur][state];
	if (ret != -1)
		return ret;
	ret = INF;

	for (int i = 0; i < N; i++) {
		if (!(state & (1 << i)) && city[cur][i]) {
			ret = min(ret, func(i, start, state + (1 << i)) + city[cur][i]);
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &city[i][j]);

	int res = INT_MAX;
	for (int i = 0; i < N; i++) {
		memset(dp, -1, sizeof(dp));
		res = min(res, func(i, i, 1 << i));
	}
	printf("%d", res);
	return 0;
}