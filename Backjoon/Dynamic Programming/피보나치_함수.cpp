#include<iostream>

using namespace std;

int N;
int dp[41][3];

int fibo(int idx)
{
	if (dp[idx][2])
		return dp[idx][2];

	if (idx == 0) {
		dp[idx][0]++;
		return 0;
	}
	if (idx == 1) {
		dp[idx][1]++;
		dp[idx][2] = 1;
		return 1;
	}

	dp[idx][2] = fibo(idx - 1) + fibo(idx - 2);
	dp[idx][1] = dp[idx - 1][1] + dp[idx - 2][1];
	dp[idx][0] = dp[idx - 1][0] + dp[idx - 2][0];
	return dp[idx][2];
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		fibo(N);
		printf("%d %d\n", dp[N][0], dp[N][1]);
	}

	return 0;
}