#include<iostream>

using namespace std;

char str[101];
int num[100000];

int main()
{
	int n;

	scanf("%d", &n);
	scanf("%s", str);
	
	for (int i = 0; i < n - 1; i++) {
		int tmp = (str[i] - 'A') * 100 + (str[i + 1] - 'A');
		num[tmp]++;
	}

	int idx = 0;
	for (int i = 0; i < 5000; i++) {
		if (num[i] > num[idx])
			idx = i;
	}
	printf("%c%c", 'A' + idx / 100, 'A' + idx % 100);


	return 0;
}