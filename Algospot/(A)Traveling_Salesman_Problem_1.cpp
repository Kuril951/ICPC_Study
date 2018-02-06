#include<iostream>
#include<algorithm>
#include<memory.h>

#define MAX_V 10
#define MAX_DISTANCE 1500000

using namespace std;

int N;
double CITY[MAX_V][MAX_V];
bool isVisited[MAX_V];

double TSP1(int C_Idx, int cnt)
{
	if (cnt == N)
		return 0;

	double ret = MAX_DISTANCE;

	isVisited[C_Idx] = true;
	for (int i = 1; i <= N; i++)
		if (!isVisited[i])
			ret = min(ret, TSP1(i, cnt + 1) + CITY[C_Idx][i]);
	isVisited[C_Idx] = false;

	return ret;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(isVisited, 0, sizeof(isVisited));

		scanf("%d", &N);

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%lf", &CITY[i][j]);

		printf("%.10lf\n", TSP1(0, 0));
	}

	return 0;
}