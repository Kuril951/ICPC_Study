#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>

#define pii pair<int, int>

using namespace std;

int P, Q, c1, c2, tmp;
vector<pii> v;

int main()
{
	scanf("%d %d", &P, &Q);
	scanf("%d %d", &c1, &c2);

	for (int i = 0; i < P; i++) {
		scanf("%d", &tmp);
		v.push_back({ tmp, 0 });
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d", &tmp);
		v.push_back({ tmp, 1 });
	}

	sort(v.begin(), v.end());

	int len = v.size();
	int a = INT_MAX, b = INT_MAX;
	int minLen = INT_MAX, cnt = 1;
	for (int i = 0; i < len; i++) {
		if (v[i].second == 0)
			a = v[i].first;
		else
			b = v[i].first;

		if (a != INT_MAX && b != INT_MAX) {
			int dist = abs(a - b);
			if (dist == minLen)
				cnt++;
			else if (dist < minLen) {
				minLen = dist;
				cnt = 1;
			}
		}
	}

	printf("%d %d", minLen + abs(c1 - c2), cnt);

	return 0;
}