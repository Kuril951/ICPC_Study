#include<iostream>
#include<algorithm>
#include<memory.h>

#define MOD 1000000007

using namespace std;

int n;
int dp[101];

int func(int idx)
{
	if (idx >= n - 1)
		return 1;

	int &ret = dp[idx];

	if (ret)
		return ret;

	return ret = (func(idx + 1) + func(idx + 2)) % MOD;
}

int main()
{
	int T;
	
	scanf("%d", &T);
	
	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		printf("%d\n", func(0));
	}

	return 0;
}