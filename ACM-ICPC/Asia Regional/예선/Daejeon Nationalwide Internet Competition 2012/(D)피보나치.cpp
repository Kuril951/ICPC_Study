//=============================
//Fibonacci Numbers
//=============================

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

long long num[47] = { 0, 1 };
queue<int> intque;

int pibonacchi(int n, int level)
{
	if (level == 46)
		return 0;

	for (int i = 46; i > 0; i--)
	{
		if (n == num[i])
		{
			intque.push(num[i]);
			return level;
		}
	}
	int ret;

	for (int i = 45; i > 0; i--)
		if (n > num[i])
			if (ret = pibonacchi(n - num[i], level + 1))
			{
				intque.push(num[i]);
				return ret;
			}
}

int main()
{
	for (int i = 2; i < 46; i++)
		num[i] = num[i - 1] + num[i - 2];

	int T, n;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		for (int i = pibonacchi(n, 1); i > 0; i--)
		{
			printf("%d", intque.front());
			intque.pop();
			if (i != 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
