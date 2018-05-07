#include<iostream>
#include<algorithm>

using namespace std;

int num[300000];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	sort(num, num + n);

	int a = num[0];
	if (k == 0) {
		if (num[0] == 1)
			a = -1;
		else
			a = num[0] - 1;
	}
	if (k != 0) {
		a = num[k - 1];
		if (n != k && num[k] == num[k - 1])
			a = -1;
	}
	printf("%d", a);
	return 0;
}