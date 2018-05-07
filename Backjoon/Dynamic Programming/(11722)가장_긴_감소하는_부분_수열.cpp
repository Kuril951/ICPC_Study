#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

vector<int> num;

int main()
{
	int N, tmp;

	scanf("%d", &N);

	num.push_back(-1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);

		if (tmp < num.back())
			num.push_back(tmp);
		else {
			auto it = lower_bound(num.begin(), num.end(), tmp, greater<int>());
			*it = tmp;
		}
	}

	printf("%d", num.size());

	return 0;
}