#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int arr[1000001], s[1000001];
vector<int> res;

int main()
{
	int n, tmp;
	vector<int> num;

	scanf("%d", &n);

	num.push_back(INT_MAX);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
		tmp = s[i];
		if (num.back() < tmp) {
			num.push_back(tmp);
			arr[i] = num.size();
		}
		else {
			auto it = lower_bound(num.begin(), num.end(), tmp);
			*it = tmp;
			arr[i] = it - num.begin() + 1;
		}
	}
	int cnt = num.size();
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == cnt) {
			res.push_back(s[i]);
			cnt--;
		}		
	}
	printf("%d\n", num.size());
	for (int i = res.size() - 1; i >= 0; i--) {
		printf("%d ", res[i]);
	}

	return 0;
}