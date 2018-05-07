#include<iostream>
#include<vector>

using namespace std;

int n, k;
vector<int> node[300000];
int isVisited[300000];

int func(int prev, int now)
{
	if (node[now].size() != 2)
		return false;
	
	isVisited[now] = true;
	for (auto next : node[now]) {
		if (!isVisited[next]) {
			if (func(now, next))
				return true;
		}
		else if (next != prev)
			return true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &k);

	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!isVisited[i] && func(-1, i))
			cnt++;
	}

	printf("%d", cnt);


	return 0;
}