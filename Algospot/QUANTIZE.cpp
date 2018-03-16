#include<iostream>
#include<algorithm>
#include<limits.h>
#include<memory.h>

#define MAX_N 100000001

using namespace std;

int N, S;	// N: 수열의 길이, S: 사용할 수의 개수
int num[101];
int dp[101][11];		// d[i][j][k] -> i: 인덱스, j: 전에 놓은 숫자, k: 바꿀수 있는 숫자 수

int calAvg(int s, int e, int avg)
{
	int ret = 0;
	for (int i = s; i <= e; i++)
		ret += (num[i] - avg) * (num[i] - avg);
	return ret;
}

int quantization(int idx, int nCnt)
{
	if (idx > N)
		return 0;
	if (nCnt == 0)
		return MAX_N;

	int &ret = dp[idx][nCnt];
	
	if (ret != -1)
		return ret;

	ret = MAX_N;

	int avg = 0, sum = 0;
	for (int i = idx; i <= N; i++) {
		sum += num[i];
		avg = (((sum * 10) / (i - idx + 1)) + 5) / 10;	// 평균 구하기(반올림)
		ret = min(ret, calAvg(idx, i, avg) + quantization(i + 1, nCnt - 1));
	}

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(dp, -1, sizeof(dp));

		scanf("%d %d", &N, &S);
		for (int i = 1; i <= N; i++)
			scanf("%d", &num[i]);

		sort(num, num + N + 1);
		printf("%d\n", quantization(1, S));
	}

	return 0;
}