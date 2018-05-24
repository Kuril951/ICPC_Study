#include<iostream>
#include<algorithm>

using namespace std;

int dp[31], N;

int func(int idx)
{
	if (idx > N)
		return 0;
	if (idx == N)
		return 1;

	int &ret = dp[idx];
	if (ret)
		return ret;

	ret = func(idx + 2) * 3;
	for (int i = idx + 4; i <= N; i += 2)
		ret += func(i) * 2;
	return ret;
}

int main()
{
	scanf("%d", &N);

	printf("%d", func(0));

	return 0;
}