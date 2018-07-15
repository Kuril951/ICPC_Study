#include<iostream>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;

int N, M, K;
int dp[301][301];
string str;

void init()
{
	for (int i = 0; i <= 201; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = min(1000000010, dp[i - 1][j - 1] + dp[i - 1][j]);
	}
}

string func(int n, int m, int k)
{
	if (n == 0) return string(m, 'o');
	if (k <= dp[n + m - 1][n - 1])
		return "-" + func(n - 1, m, k);
	return "o" + func(n, m - 1, k - dp[n + m - 1][n - 1]);
}

int main()
{
	init();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		cout << func(N, M, K) << "\n";
	}

	return 0;
}