#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int kor[101], russia[101];

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &russia[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &kor[i]);

		sort(kor, kor + n);
		sort(russia, russia + n);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (kor[i] >= russia[j]) {
					cnt++;
					russia[j] = 10000;
					break;
				}
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}