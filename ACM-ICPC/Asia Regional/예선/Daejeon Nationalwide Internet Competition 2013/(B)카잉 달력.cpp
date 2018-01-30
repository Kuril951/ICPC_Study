#include<iostream>

using namespace std;

int main()
{
	int T, M, N, x, y;
	int a[100] = { 0 };

	scanf("%d", &T);

	while (T--)
	{
		int i, n;
		scanf("%d %d %d %d", &M, &N, &x, &y);


		for (i = 0; i < M; i++)
		{
			n = (N*i + y) % M;
			if (!n) n = M;
			if (n == x) break;
		}

		if (i != M)
			printf("%d\n", N * i + y);
		else
			printf("-1\n");
	}


	return 0;
}
