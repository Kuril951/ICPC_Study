#include<iostream>

#define MAX_CNT 1001

using namespace std;

int n, m;
int box[MAX_CNT][MAX_CNT];
int check[MAX_CNT][MAX_CNT];

int main()
{
	unsigned long long sum=0;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);
			sum += box[i][j];
		}

	for (int i = 0; i < n; i++) {
		int max = 0;
		for (int j = 0; j < m; j++) {
			if (box[i][max] < box[i][j])
				max = j;
		}
		check[i][max] = 1;
		sum -= box[i][max];
	}

	for (int i = 0; i < m; i++) {
		int max = 0;
		for (int j = 0; j < n; j++) {
			if (box[max][i] < box[j][i])
				max = j;
		}
		if (!check[max][i])
			sum -= box[max][i];
	}

	printf("%lld", sum);

	return 0;
}
