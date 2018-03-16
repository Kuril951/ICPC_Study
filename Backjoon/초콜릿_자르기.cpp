#include<iostream>
#include<algorithm>
#include<limits.h>

#define MAX 301

using namespace std;

int dp[MAX][MAX];	//m x n 일때 자를 수 있는 최솟값

int func(int n, int m)
{
	if (n == 1)
		return m - 1;
	if (m == 1)
		return n - 1;

	int &ret1 = dp[n][m];
	int &ret2 = dp[m][n];

	if (ret1)
		return ret1;
	if (ret2)
		return ret2;
	ret1 = INT_MAX;
	ret2 = INT_MAX;
	for (int i = 1; i < n; i++)
		ret1 = min(ret1, func(i, m) + func(n - i, m) + 1);
	for (int i = 1; i < m; i++)
		ret2 = min(ret2, func(n, i) + func(n, m - i) + 1);

	return ret1 = ret2 = min(ret1, ret2);
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);

	printf("%d", func(n, m));

	return 0;
}