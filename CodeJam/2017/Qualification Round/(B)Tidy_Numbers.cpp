#include<iostream>

using namespace std;


int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		long long N, res;
		scanf("%lld", &N);

		while (1)
		{
			int cnt = 1;
			res = N;
			// n자리수 <= n+1자리수
			while (res && (res / 10) % 10 <= res % 10) {
				res /= 10;
				cnt++;
			}

			if (!res)
				break;

			res = res / 10 - 1;
			for(int i=0; i<cnt; i++)
				res = res * 10 + 9;
			N = res;
		}

		printf("Case #%d: %lld\n", t, N);
	}

	return 0;
}