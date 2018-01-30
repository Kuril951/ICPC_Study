#include<iostream>

using namespace std;

int dp[1000];

int main()
{
	int n;
	int initN;
	scanf("%d", &n);

	initN = n;
	
	do {
		if(n < 1000)
			dp[n] = 1;
		int tmp = 0;
		while (n) {
			tmp += (n % 10)*(n % 10);
			n /= 10;
		}
		n = tmp;
	} while (n != 1 && !dp[n]);

	if (n == 1)
		printf("HAPPY");
	else
		printf("UNHAPPY");


	return 0;
}