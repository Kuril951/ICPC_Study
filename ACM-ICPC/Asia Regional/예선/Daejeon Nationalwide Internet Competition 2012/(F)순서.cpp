#include<iostream>

using namespace std;

int num[1000], n;
bool isUsed[1000];

int correct[1000];
int correct2[1000];

void correctAnswer()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (correct[i] > correct[j])
				num[i]++;
}

int main()
{
	int T, flg;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);

		for (int i = 0; i <= n; i++)
			num[i] = 0;

		flg = false;

		for (int i = 1; i <= n; i++)
			scanf("%d", &num[i]);

		for (int i = 1; i <= n; i++)
			if (num[i] > i - 1)
				flg = true;

		for (int i = n; i > 0 && !flg; i--)
		{
			isUsed[num[i]] = true;
			for (int j = i - 1; j > 0; j--)
			{
				if (num[i] <= num[j])
					num[j]++;
				while (num[j] <= n && isUsed[num[j]]) num[j]++;
				if (num[j] > n)
				{
					flg = true;
					break;
				}
			}
		}

		if (flg)
			printf("IMPOSSIBLE\n");
		else
		{
			for (int i = 1; i <= n; i++)
			{
				printf("%d", num[i] + 1);
				if (i != n)
					printf(" ");
			}
			printf("\n");
		}

		for (int i = 0; i < 1000; i++)
			isUsed[i] = 0;
	}

	return 0;
}
