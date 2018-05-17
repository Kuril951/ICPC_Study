#include<iostream>

using namespace std;

int main()
{
	int T;
	
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		int N;
		scanf("%d", &N);
		int res = N - 1;

		// b(x^k + x^k-1 + ... + 1) = N
		for (int x = 2; x * x <= N; x++)
		{
			int remainer = N % x, tmp = N;
			bool flg = false;
			while (tmp) {
				if (tmp % x != remainer) {
					flg = true;
					break;
				}
				tmp /= x;
			}
			if (!flg) {
				res = x;
				break;
			}
		}

		// b^2 < b(x+1) = N
		// b < sqrt(N) -> (x+1) > sqrt(N)
		if (res == N - 1) {
			for (int b = 1; b * b <= N; b++) {
				if (N % b == 0) {
					int tmp = N / b - 1;
					if (tmp > b)
						res = tmp;
				}
			}
		}

		printf("Case #%d\n", t);
		// N ¿Ã 2¿œ∂ß
		if (res < 2)
			printf("%d\n", res + 2);
		else
			printf("%d\n", res);
	}

	return 0;
}