#include<iostream>
#include<algorithm>

using namespace std;

typedef struct {
	int t1, t2;
}Lunch;

bool cmp(const Lunch l1, const Lunch l2)
{
	return l1.t2 > l2.t2;
}

int main()
{
	int T, N;
	Lunch lunch[10001];

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
			scanf("%d", &lunch[i].t1);
		for (int i = 0; i < N; i++)
			scanf("%d", &lunch[i].t2);

		sort(lunch, lunch + N, cmp);

		int t1 = lunch[0].t1, t2 = lunch[0].t2;

		for (int i = 1; i < N; i++)
		{
			t1 += lunch[i].t1;

			if (t2 > lunch[i].t1)
				t2 -= lunch[i].t1;
			else
				t2 = 0;
			t2 = max(t2, lunch[i].t2);
		}

		printf("%d\n", t1 + t2);
	}

	return 0;
}