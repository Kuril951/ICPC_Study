#include<iostream>
#include<algorithm>

using namespace std;

int N, maxN = 0;
int T[100], P[100], dp[100];

int func(int idx)
{
	if (idx == N)
		return 0;

	int &ret = dp[idx];
	if (ret)
		return ret;

	for (int i = idx; i < N; i++) {
		if(i + T[i] <= N)
			ret = max(ret, func(i + T[i]) + P[i]);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &T[i], &P[i]);

	printf("%d", func(0));

	return 0;
}