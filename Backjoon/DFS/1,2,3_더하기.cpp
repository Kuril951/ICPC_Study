#include<iostream>

int dp[12];

int func(int n)
{
	if (n < 0) 
		return 0;
	if (n == 0)
		return 1;

	int &ret = dp[n];

	if (ret)
		return ret;

	for (int i = 1; i <= 3; i++)
		ret += func(n - i);
	return ret;
}

int main()
{
	int T, n;

	scanf("%d", &T);

	func(11);

	while (T--)	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}

// a(n) = a(n-1) + a(n-2) + a(n-3)