#include<iostream>
#include<memory.h>

using namespace std;

int N, M;
int movie[100001];
int tree[200002];

void update(int i, int num)
{
	while (i <= N + M) {
		tree[i] += num;
		i += (i & -i);
	}
}

int movieRank(int i)
{
	int rank = 0;

	while (i > 0) {
		rank += tree[i];
		i -= (i & -i);
	}

	return rank;
}

void init()
{
	memset(tree, 0, sizeof(tree));
	for (int i = 1; i <= N; i++)
		movie[i] = i + M;
	for (int i = M + 1; i <= M + N; i++)
		update(i, 1);
}

int main()
{
	int T;
	
	scanf("%d", &T);
	while (T--) {
		
		scanf("%d %d", &N, &M);

		init();

		for (int i = 0; i < M; i++)
		{
			int select;
			scanf("%d", &select);

			printf("%d ", movieRank(movie[select]) - 1);

			update(movie[select], -1);
			movie[select] = M - i;
			update(movie[select], 1);
		}
		printf("\n");
	}
	

	return 0;
}