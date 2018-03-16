#include<iostream>

#define ll long long

using namespace std;

ll nextNum(ll num)
{
	ll tmp = num, cnt = 10, res;

	while ((tmp / 10) % 10 <= tmp % 10) {
		cnt *= 10;
		tmp /= 10;
	}

	tmp /= 10;

	while ((tmp / 10) % 10 >= tmp % 10) {
		cnt *= 10;
		tmp /= 10;
	}

	res = ((num / cnt) * cnt) - 1;

	return res;
}

int main()
{
	int T;

	cin >> T;
	for (int i = 1; i <= T; i++) {
		ll res, num;
		bool flg = true;

		cin >> num;
		//  N ~ 1 순으로 확인
		while (flg)	{
			ll tmp = num--;
			//  오름차순인지 확인
			while (true) {
				if (tmp == 0) {
					res = num + 1;
					flg = false;
					break;
				}
				// 오름 차순이 아닐경우
				if (tmp % 10 < (tmp / 10) % 10) {
					num = nextNum(num + 1);
					break;
				}
				tmp /= 10;
			}
		}

		cout << "Case #" << i << ": " << res << "\n";
	}

	return 0;
}