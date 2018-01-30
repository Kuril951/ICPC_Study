#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> city[100001];
int dp[100001];

int func(int n)
{
	int &ret = dp[n];
	if (ret)
		return ret;
	
	int cNearCnt = city[n].size();

	for (int next : city[n])
		if(cNearCnt < city[next].size())
			ret = max(ret, func(next) + 1);

	return ret;
}

int main()
{

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		//Add neighbor node
		city[u].push_back(v);
		city[v].push_back(u);
	}

	int res = 0;

	for (int i = 0; i < n; i++)
		res = max(res, func(i));

	printf("%d", res + 1);

	return 0;
}