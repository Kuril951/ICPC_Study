#include<iostream>
#include<memory.h>

using namespace std;

bool isSymmetry(int n)
{
	int flg = 0;

	for (int i = 64; i > 1; i--)
	{
		int a[22] = { 0 }, tmp = n;
		int idx = 0;
		flg = true;

		while (tmp / i != 0)
		{
			a[idx++] = tmp%i;
			tmp /= i;
		}
		a[idx] = tmp%i;

		for (int j = 0; j < (idx+1) / 2; j++)
		{
			if (a[j] != a[idx - j])
			{
				flg = false;
				break;
			}
		}
		if (flg == true)
			return true;
	}
	return false;
}

int main()
{
	int T, n;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		printf("%d\n",isSymmetry(n));
	}

	return 0;
}
