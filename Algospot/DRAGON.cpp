#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int N, P, L;
int dp[100];

void init()
{
	dp[0] = 1;
	for (int i = 1; i < 51; i++)
		dp[i] = min(1000000010, 2 * dp[i - 1] + 2);
}

void func(const string &str, int level)
{
	if (L <= 0)
		return;
	if (level == N) {
		if (P <= str.size()) {
			for (int i = P - 1; i < str.size(); i++) {
				if (L-- <= 0)
					return;
				cout << str[i];
			}
			P = 1;
		}
		return;
	}

	for (auto ch : str) {
		if (L <= 0)
			return;
		if (ch == 'X' || ch == 'Y') {
			if (dp[N - level] < P)
				P -= dp[N - level];
			else if(ch == 'X')
				func("X+YF", level + 1);
			else
				func("FX-Y", level + 1);
		}
		else if (P == 1) {
			cout << ch;
			L--;
		}
		else
			P--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	int T;
	
	cin >> T;

	while (T--)
	{
		cin >> N >> P >> L;
		func("FX", 0);
		cout << "\n";
	}

	return 0;
}#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int N, P, L;
int dp[100];

void init()
{
	dp[0] = 1;
	for (int i = 1; i < 51; i++)
		dp[i] = min(1000000010, 2 * dp[i - 1] + 2);
}

void func(const string &str, int level)
{
	if (L <= 0)
		return;
	if (level == N) {
		if (P <= str.size()) {
			for (int i = P - 1; i < str.size(); i++) {
				if (L-- <= 0)
					return;
				cout << str[i];
			}
			P = 1;
		}
		return;
	}

	for (auto ch : str) {
		if (L <= 0)
			return;
		if (ch == 'X' || ch == 'Y') {
			if (dp[N - level] < P)
				P -= dp[N - level];
			else if(ch == 'X')
				func("X+YF", level + 1);
			else
				func("FX-Y", level + 1);
		}
		else if (P == 1) {
			cout << ch;
			L--;
		}
		else
			P--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	int T;
	
	cin >> T;

	while (T--)
	{
		cin >> N >> P >> L;
		func("FX", 0);
		cout << "\n";
	}

	return 0;
}