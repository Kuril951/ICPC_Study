#include<iostream>
#include<algorithm>
#include<memory.h>
#include<cstring>

using namespace std;

char pi[10001];
int dp[10001];
int score[5] = { 1,2,4,5,10 };
int numlen;

int difficulty(int idx, int len)
{
	int rule = pi[idx + 1] - pi[idx];
	int flg[5] = { 0 };

	for (int i = idx; i < idx + len - 1; i++) {
		if (pi[i + 1] != pi[i])		// 1111
			flg[0] = 1;
		if (!((rule == 1 || rule == -1) && (pi[i + 1] - pi[i] == rule)))	// 1234 , 4321
			flg[1] = 1;
		if (!(pi[i+1] != pi[i] && pi[i + 1] - pi[i] == rule * pow(-1, i - idx)))	// 32323
			flg[2] = 1;
		if (!(pi[i+1] != pi[i] && pi[i + 1] - pi[i] == rule))	// 148, 8642
			flg[3] = 1;
	}

	for (int i = 0; i < 5; i++)
		if (!flg[i])
			return score[i];
}
int func(int idx)
{
	if (idx + 3 > numlen)
		return 999999999;

	int &ret = dp[idx];

	if (ret)
		return ret;
	ret = 999999999;
	for (int i = 3; i <= 5; i++) {
		if (idx + i < numlen)
			ret = min(ret, func(idx + i) + difficulty(idx, i));
		else if (idx + i == numlen)
			ret = min(ret, difficulty(idx, i));
	}

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%s", pi);
		numlen = strlen(pi);

		printf("%d\n", func(0));
	}

	return 0;
}