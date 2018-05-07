#include<iostream>

using namespace std;

int n, k;

int main()
{
	scanf("%d %d", &n, &k);

	while (k)
	{
		int tmp = n % 10;

		if (tmp == 0) {
			n /= 10;
			k--;
		}
		else if (tmp <= k) {
			n -= tmp;
			k -= tmp;
		}
		else {
			n -= k;
			k = 0;
		}
	}
	printf("%d", n);

	return 0;
}