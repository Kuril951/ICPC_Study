#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define MAX_V 75004
#define ll long long

using namespace std;

int N;
vector<int> tree(MAX_V, 0);
vector<pair<int, int>> land;

void update(int i)
{
	while (i <= N) {
		tree[i]++;
		i += (i & -i);
	}
}

ll sum(int i)
{
	ll ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}


bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a.first < b.first)
		return true;
	else if (a.first == b.first) {
		if (a.second > b.second)
			return true;
		return false;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		fill(tree.begin(), tree.end(), 0);
		land.clear();

		set<int> y;
		map<int, int> rltvY;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			y.insert(b);
			land.emplace_back(make_pair(a, b));
		}
		int idx = 1;
		for (auto i : y)
			rltvY[i] = idx++;

		sort(land.begin(), land.end(), comp);

		ll res = 0;
		for (int i = 0; i < N; i++) {
			int relativeY = rltvY[land[i].second];
			res += (ll)sum(N) - (ll)sum(relativeY - 1);
			update(relativeY);
		}

		printf("%lld\n", res);
	}

	return 0;
}