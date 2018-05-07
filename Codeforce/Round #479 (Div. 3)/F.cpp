#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int node[300000];
map<int, int>mp;
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &node[i]);
	for (int i = 1; i <= n; i++) {
		//mp[node[i]] : node[i] - 1인 수의 최대 길이 + 1
		mp[node[i]] = mp[node[i] - 1] + 1;
		if (mp[node[i]]>mp[ans])
			ans = node[i];
	}
	vector<int>num;
	for (int i = n; i >= 1; i--) {
		if (node[i] == ans) {
			num.push_back(i);
			ans--;
		}
	}
	reverse(num.begin(), num.end());
	printf("%d\n", num.size());
	for (auto i : num)
		printf("%d ", i);
	return 0;
}