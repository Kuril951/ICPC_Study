#include<iostream>

using namespace std;

int pre[1001], ino[1001];
int idx = -1;

void func(int s, int e)
{
	if (s <= e)
		idx++;
	if (s == e)
	{
		printf("%d ", ino[s]);
		return;
	}
	for (int i = s; i <= e; i++)
	{
		if (pre[idx] == ino[i])
		{
			func(s, i - 1);
			func(i + 1, e);
			printf("%d ", ino[i]);
			break;
		}
	}


}


int main()
{
	int T, n;

	cin >> T;

	while (T--)
	{
		cin >> n;
		idx = -1;
		for (int i = 0; i<n; i++)
			scanf("%d", &pre[i]);
		for (int i = 0; i<n; i++)
			scanf("%d", &ino[i]);

		func(0, n - 1);

		printf("\n");

	}

	return 0;
}
