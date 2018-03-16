#include<iostream>
#include<algorithm>

using namespace std;

int n;
int dp[51][51];
int num[51];

int func(int left, int right)
{
	if (left == right)
		return num[left];
	if (left > right)
		return 0;

	int &ret = dp[left][right];

	if (ret)
		return ret;

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);


	}


	return 0;
}