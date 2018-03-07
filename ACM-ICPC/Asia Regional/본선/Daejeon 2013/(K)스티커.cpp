#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

int n;
int num[2][100001];
int dp[2][100001];

// way : 선택 된거, idx : 스티커 index
int sticker(bool way, int idx)
{
	if (n <= idx)
		return 0;

	int &ret = dp[way][idx];

	if (ret)
		return ret;

	// 바로옆 대각선 스티커, 현재 선택한 스티커의 두칸 옆 스티커
	ret = max(max(sticker(!way, idx + 1), sticker(way, idx + 2)), sticker(!way, idx + 2)) + num[way][idx];
	
	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)	
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &num[i][j]);
		printf("%d\n", max(sticker(0, 0), sticker(1, 0)));
	}

	return 0;
}