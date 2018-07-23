#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int n, m, res;
int fr[51];
map<string, int> name;
// foods[i] : i번째 음식을 먹을수 있는 사람들, peop[i] : i번째 사람이 먹을수있는 음식들
vector<int> foods[51], peop[51]; 

void func(int cnt)
{
	bool flg = true;
	for(int i=0; i<n; i++)
		if (!fr[i]) {
			flg = false;
			break;
		}
	if (flg) {
		res = min(res, cnt);
		return;
	}

	int idx = 51, maxN = 51;
	for (int i = 0; i < n; i++) {
		if (!fr[i] && peop[i].size() < maxN) {
			maxN = peop[i].size();
			idx = i;
		}
	}

	for (auto food : peop[idx]) {
		for (auto pers : foods[food])
			++fr[pers];
		func(cnt + 1);
		for (auto pers : foods[food])
			--fr[pers];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		res = 10000000;
		string tmp;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			name[tmp] = i;
		}

		for (int i = 0; i < m; i++) {
			int tmpN;
			cin >> tmpN;
			for (int j = 0; j < tmpN; j++) {
				cin >> tmp;
				peop[name[tmp]].push_back(i);
				foods[i].push_back(name[tmp]);
			}
		}
		func(0);
		cout << res << "\n";

		for (int i = 0; i < n; i++)
			peop[i].clear();
		for (int i = 0; i < m; i++)
			foods[i].clear();
		name.clear();
	}

	return 0;
}
