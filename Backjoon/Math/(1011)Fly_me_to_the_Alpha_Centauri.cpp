#include<iostream>
#include<cmath>

#define ll long long

using namespace std;

int main()
{
	int T, x, y;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &x, &y);
		// ��Ģ ����
		ll n = ceil(sqrt(y - x));
		if ((y - x) - (n*(n - 1)) > 0)
			printf("%lld\n", 2 * n - 1);
		else
			printf("%lld\n", 2 * n - 2);
	}
	
	return 0;
}