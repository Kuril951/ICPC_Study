#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<memory.h>

using namespace std;

int card[1000];
int dp[2][1000][1000];		//가져간수(차례,왼쪽,오른쪽)

int card_game(int left, int right, bool turn_Gnwoo)
{
	if (left == right && turn_Gnwoo)
		return card[left];
	else if (left == right && !turn_Gnwoo)
		return 0;

	int &ret = dp[turn_Gnwoo][left][right];

	if (ret != 0)
		return ret;

	if (turn_Gnwoo)
		ret = max(card_game(left + 1, right, !turn_Gnwoo) + card[left], card_game(left, right - 1, !turn_Gnwoo) + card[right]);
	else
		ret = min(card_game(left + 1, right, !turn_Gnwoo), card_game(left, right - 1, !turn_Gnwoo));

	return ret;
}


int main()
{
	int T, N;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < N; i++)
			scanf("%d", &card[i]);

		printf("%d\n", card_game(0, N -1, 1));
	}

	return 0;
}
