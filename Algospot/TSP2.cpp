#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX_V 16
#define MAX_DISTANCE 1500000

using namespace std;

int N;
double CITY[MAX_V][MAX_V];
double dp[MAX_V][1<<MAX_V];

double TSP1(int C_Idx, int visited)
{
	if(visited == (1 << (N+1)) - 1)
		return 0;

	double &ret = dp[C_Idx][visited];
	if (ret != -1)
		return ret;
	ret = MAX_DISTANCE;

	for (int i = 1; i <= N; i++)
		if ((visited & (1 << i)) == 0)
			ret = min(ret, TSP1(i, visited + (1<< i)) + CITY[C_Idx][i]);

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		for (int i = 0; i <= N; i++)
			for (int j = 0; j < (1 << MAX_V); j++)
				dp[i][j] = -1;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%lf", &CITY[i][j]);

		printf("%.10lf\n", TSP1(0, 1));
	}

	return 0;
}