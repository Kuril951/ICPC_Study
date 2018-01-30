#include<iostream>
#include<algorithm>
#include<functional>


using namespace std;

int n;
int arr[10001];

int main()
{

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n, greater<int>());

	int res[4] = { 0 };

	res[0] = arr[0] * arr[1];
	res[1] = res[0] * arr[2];
	res[2] = arr[n - 1] * arr[n - 2];
	res[3] = res[2] * arr[0];

	int fres = max(max(res[0], res[1]), max(res[2], res[3]));
	printf("%d", fres);

	return 0;
}
