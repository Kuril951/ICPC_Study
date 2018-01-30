#include<iostream>
#include<algorithm>
#include<memory.h>
#define ll long long

ll team[1001][3] = { 0 };
ll max, min;

void gidae(int n)
{
	max = -1;
	min = 999999999;

	for (int i = 1; i <= n; i++)
	{
		if (team[i][0] == 0 && team[i][1] == 0)
			team[i][2] = 0;
		else
			team[i][2] = (((team[i][0] * team[i][0]) * 1000) / (double)((team[i][0] * team[i][0]) + (team[i][1] * team[i][1])));

		if (max < team[i][2])
			max = team[i][2];
		if (min > team[i][2])
			min = team[i][2];
	}
}

int main()
{
	int T, n, m;

	scanf("%d", &T);

	while (T--)
	{
		int a[4];

		scanf("%d %d", &n, &m);

		memset(team, 0, sizeof(team));

		for (int i = 0; i < m; i++)
		{
			for (int i = 0; i < 4; i++)
				scanf("%d", &a[i]);
			team[a[0]][0] += a[2];
			team[a[1]][1] += a[2];
			team[a[0]][1] += a[3];
			team[a[1]][0] += a[3];
		}

		gidae(n);

		printf("%lld\n%lld\n", max, min);

	}

	return 0;
}
