#include<iostream>
#include<algorithm>
#include<limits.h>
#include<memory.h>

#define MAX_N 100000001

using namespace std;

int N, S;	// N: ������ ����, S: ����� ���� ����
int num[101];
int dp[101][11];		// d[i][j][k] -> i: �ε���, j: ���� ���� ����, k: �ٲܼ� �ִ� ���� ��

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
		avg = (((sum * 10) / (i - idx + 1)) + 5) / 10;	// ��� ���ϱ�(�ݿø�)
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