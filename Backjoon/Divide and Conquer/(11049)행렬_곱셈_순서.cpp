#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int N;
pair<int, int> matrix[501];
int dp[501][501];

int func(int s, int e)
{
	if (s + 1 == e)
		return 0;

	int &ret = dp[s][e];

	if (ret)
		return ret;

	ret = INT_MAX;
	int tmp = matrix[s].first * matrix[e - 1].second;
	for (int i = s + 1; i < e; i++)
		ret = min(ret, func(s, i) + func(i, e) + tmp * matrix[i - 1].second);

	return ret;
}

int main()
{
	int a, b;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &matrix[i].first, &matrix[i].second);

	printf("%d", func(0, N));

	return 0;
}