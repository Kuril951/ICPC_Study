#include<iostream>

#define MOD 1000000007
#define ll long long

using namespace std;

int n;
ll dp[101] = {1, 1, 2 };

int main()
{
	int T;

	scanf("%d", &T);

	for (int i = 3; i <= 100; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

	while (T--)
	{
		scanf("%d", &n);
		
		//printf("%d\n", dp[n]);
		
		if (n % 2)
			printf("%lld\n", (dp[n] - dp[n / 2] + MOD) % MOD);
		else
			printf("%lld\n", (dp[n] - dp[n / 2] - dp[(n / 2) - 1] + (MOD*2)) % MOD);
	}

	return 0;
}