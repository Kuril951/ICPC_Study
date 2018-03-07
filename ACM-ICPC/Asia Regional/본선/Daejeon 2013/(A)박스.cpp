#include<iostream>

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int cnt1[101] = { 0 };
		int m, n, tmp, res = 0;

		scanf("%d %d", &m, &n);

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &tmp);
				if (tmp == 1) cnt1[j]++;
				else res += cnt1[j];
			}
		}
		printf("%d\n", res);
	}

	return 0;
}