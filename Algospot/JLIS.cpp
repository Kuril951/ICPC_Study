#include<iostream>
#include<algorithm>
#include<memory.h>
#include<climits>

using namespace std;

int n, m;
int num1[101], num2[101];
int dp[101][101];

int func(int idx1, int idx2)
{
	int &ret = dp[idx1][idx2];
	if (ret)
		return ret;
	int bigN = max(num1[idx1], num2[idx2]);

	for (int i = idx1 + 1; i <= n; i++)
		if (bigN < num1[i])
			ret = max(ret, func(i, idx2) + 1);
	for (int i = idx2 + 1; i <= m; i++)
		if (bigN < num2[i])
			ret = max(ret, func(idx1, i) + 1);

	return ret;
}

int main()
{
	int c;

	scanf("%d", &c);

	while (c--)
	{
		memset(dp, 0, sizeof(dp));
		num1[0] = num2[0] = INT_MIN;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++)
			scanf("%d", &num1[i]);
		for (int i = 1; i <= m; i++)
			scanf("%d", &num2[i]);

		printf("%d\n", func(0, 0));
	}

	return 0;
}