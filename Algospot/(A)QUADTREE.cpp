#include<iostream>
#include<memory.h>

using namespace std;

char str[1001];

// return value : 다음 문자의 index
int quadtree(int s)
{
	if (str[s++] != 'x')
		return s;

	int a[5] = { s };

	for (int i = 0; i < 4; i++)
		a[i + 1] = quadtree(a[i]);

	char tmp[1001];
	int idx = 0;

	for (int i = a[2]; i < a[3]; i++)
		tmp[idx++] = str[i];
	for (int i = a[3]; i < a[4]; i++)
		tmp[idx++] = str[i];
	for (int i = a[0]; i < a[1]; i++)
		tmp[idx++] = str[i];
	for (int i = a[1]; i < a[2]; i++)
		tmp[idx++] = str[i];

	for (int i = a[0]; i < a[4]; i++)
		str[i] = tmp[i - a[0]];
		
	return a[4];
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%s", str);

		quadtree(0);

		printf("%s\n", str);
	}

	return 0;
}