#include<iostream>
#include<string.h>

using namespace std;

int main()
{
	int T, len, check;
	char arr[100];

	scanf("%d", &T);

	while (T--)
	{
		scanf("%s", arr);

		len = strlen(arr);
		check = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] == '(')
				++check;
			else
				--check;

			if (check < 0)
				break;
		}
		if (check != 0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	return 0;
}
