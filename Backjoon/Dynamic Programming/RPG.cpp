#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;

typedef struct {
	int str, intl, reward;
}quest;

int N;
vector<quest> Q;

int dp[1001][1001];
bool isUsed[101];

int RPG(int str, int intl)
{
	str = str > 1000 ? 1000 : str;
	intl = intl > 1000 ? 1000 : intl;
	int &ret = dp[str][intl];
	if (ret != -1)
		return ret;

	int cnt = 0, status = 0;
	ret = 0;
	vector<int> select;

	for (int i = 0; i < N; i++)	{
		if (Q[i].str <= str || Q[i].intl <= intl) {
			if (!isUsed[i]) {
				status += Q[i].reward;
				select.push_back(i);
				isUsed[i] = 1;
			}
			cnt++;
		}
	}
	ret = cnt;

	for (int i = 0; i <= status; i++)
		ret = max(ret, RPG(str + i, intl + status - i));

	for (int i : select)
		isUsed[i] = 0;

	return ret;
}

int main()
{
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));
	Q.assign(N, { 0,0,0 });
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &Q[i].str, &Q[i].intl, &Q[i].reward);

	printf("%d\n", RPG(1, 1));

	return 0;
}