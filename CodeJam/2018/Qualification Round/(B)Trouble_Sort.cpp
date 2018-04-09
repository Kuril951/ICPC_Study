#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>

#define ll long long

using namespace std;

int N;
ll num5[100010];
ll num2[100010];
ll num[100010];

int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		memset(num5, 0, sizeof(num5));
		memset(num2, 0, sizeof(num2));
		memset(num, 0, sizeof(num));

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			if (i % 2)
				scanf("%lld", &num5[i / 2]);
			else
				scanf("%lld", &num2[i / 2]);
		}
		sort(num5, num5 + N / 2);
		sort(num2, num2 + (N + 1) / 2);

		for (int i = 0; i < N; i++)
			num[i] = (i % 2) ? num5[i / 2] : num2[i / 2];

		int flg = -1;
		for (int i = 0; i < N - 1; i++)
			if (num[i] > num[i + 1]) {
				flg = i;
				break;
			}

		printf("Case #%d: ", t);
		if (flg == -1)
			printf("OK\n");
		else
			printf("%d\n", flg);
	}

	return 0;
}