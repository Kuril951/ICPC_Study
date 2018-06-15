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
	int N, M;
	
	memset(p, -1, sizeof(p));
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 0)
			merge(b, c);
		else {
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}