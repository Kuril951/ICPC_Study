#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int main()
{
	int n, tmp;
	vector<int> num;

	scanf("%d", &n);
	
	num.push_back(INT_MAX);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &tmp);
		if (num.back() < tmp)
			num.push_back(tmp);
		else {
			auto it = lower_bound(num.begin(), num.end(), tmp);
			*it = tmp;
		}
	}
	printf("%d", num.size());

	return 0;
}