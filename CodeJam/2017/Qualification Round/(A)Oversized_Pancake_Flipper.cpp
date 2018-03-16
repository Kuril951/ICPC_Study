#include<iostream>
#include<cstring>

int main()
{
	int T, k;
	char pancake[1001];

	scanf("%d", &T);

	for(int t=1; t<=T; t++)
	{
		int cnt = 0;
		scanf("%s %d", pancake, &k);

		for (int i = 0; i <= strlen(pancake) - k; i++) {
			if (pancake[i] == '-') {
				for (int j = 0; j < k; j++)
					pancake[i + j] = (pancake[i + j] == '-') ? '+' : '-';
				cnt++;
			}
		}
		for(int i=0; i<strlen(pancake); i++)
			if (pancake[i] == '-') {
				cnt = -1;
				break;
			}

		printf("Case #%d: ", t);
		if (cnt == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", cnt);
	}
	return 0;
}