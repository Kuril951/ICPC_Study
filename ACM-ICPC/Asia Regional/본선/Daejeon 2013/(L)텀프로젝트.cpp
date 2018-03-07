#include<iostream>
#include<memory.h>

#define MAX_V 100001

int N;
int num[MAX_V], isVisited[MAX_V];

int tumProject(int idx)
{
	int i = idx, cnt = 0;

	while (!isVisited[i]) {
		isVisited[i] = true;
		i = num[i];
	}

	for (int j = idx; j != i; j = num[j])
		cnt++;
	return cnt;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		int cnt = 0;
		
		memset(isVisited, 0, sizeof(isVisited));

		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &num[i]);
		for (int i = 1; i <= N; i++)
			if (!isVisited[i])
				cnt += tumProject(i);
		printf("%d\n", cnt);
	}

	return 0;
}