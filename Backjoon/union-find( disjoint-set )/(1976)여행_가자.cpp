#include<iostream>
#include<cstring>

using namespace std;

int p[1000001];

int find(int a)
{
	if (p[a] < 0)
		return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main()
{
	int N, M, tmp;

	memset(p, -1, sizeof(p));

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &tmp);
			if (tmp)
				merge(i, j);
		}
	}

	int plane[3000];
	for (int i = 0; i < M; i++)
		scanf("%d", &plane[i]);

	for (int i = 0; i < M - 1; i++) {
		if (find(plane[i]) != find(plane[i + 1])) {
			printf("NO");
			return 0;
		}
	}
	printf("YES");

	return 0;
}