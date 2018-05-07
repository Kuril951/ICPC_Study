#include<iostream>
#include<vector>
#include<memory.h>

#define ll long long

using namespace std;

ll num[101];
int isVisited[101];
int n;
vector<ll> res;

ll func(ll a, int cnt)
{	
	for (int i = 0; i < n; i++) {
		if (a == num[i] && !isVisited[i]) {
			isVisited[i] = 1;
			if (cnt == n) {
				res.push_back(num[i]);
				return true;
			}
			if (a % 3 == 0 && func(a / 3, cnt+1)) {
				res.push_back(num[i]);
				return true;
			}
			if (func(a * 2, cnt + 1)) {
				res.push_back(num[i]);
				return true;
			}
			isVisited[i] = 0;
		}
	}
	return false;
}


int main()
{

	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		if (func(num[i], 1))
			break;
	}

	for (int i = n - 1; i >= 0; i--)
		cout << res[i] << " ";
	
	return 0;
}