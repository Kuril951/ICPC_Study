#include<iostream>
#include<cstring>
#include<algorithm>

#define MOD 201

using namespace std;

int n, m;
int dp[201];
int price[20], pref[20];

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int res = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d %d", &a, &pref[i]);
			price[i] = a / 100;
		}
		m /= 100;
		for (int budget = 1; budget <= m; budget++) {
			int maxPref = 0;
			for (int j = 0; j < n; j++) {
				if (budget >= price[j])
					maxPref = max(maxPref, dp[(budget - price[j]) % MOD] + pref[j]);
			}
			dp[budget % MOD] = maxPref;
			res = max(res, maxPref);
		}
		printf("%d\n", res);
	}

	return 0;
}