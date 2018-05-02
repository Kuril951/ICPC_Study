#include<iostream>
#include<algorithm>

#define ll long long
using namespace std;

int n;
int map[110][110];
ll dp[101][101];

int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1)
				break;
			dp[i + map[i][j]][j] += dp[i][j];
			dp[i][j + map[i][j]] += dp[i][j];
		}
	}

	printf("%lld", dp[n-1][n-1]);

	return 0;
}