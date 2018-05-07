#include<iostream>

using namespace std;

int main()
{
	int N, dp[1001] = { 0 }, res = 0;
	int num[1001];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int maxN = 0, tmp;
		scanf("%d", &tmp);
		num[i] = dp[i] = tmp;
		for (int j = 0; j < i; j++) {
			if (num[j] < tmp && maxN < dp[j])
				maxN = dp[j];
		}
		dp[i] += maxN;
		if (dp[i] > res)
			res = dp[i];
	}
	printf("%d", res);
	return 0;
}