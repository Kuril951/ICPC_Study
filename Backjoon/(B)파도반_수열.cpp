#include<iostream>

unsigned long long num[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

int main()
{
	int T, idx;

	for (int i = 11; i <= 100; i++)
		num[i] = num[i - 2] + num[i - 3];

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &idx);
		printf("%lld\n", num[idx]);
	}
	return 0;
}