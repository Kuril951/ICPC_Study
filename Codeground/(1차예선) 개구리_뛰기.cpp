#include <iostream>
#include <memory.h>
#include <algorithm>
#include <map>
#include<climits>

using namespace std;

int Answer;
int n, stones[1010000], jump;


int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int tmp;
		Answer = 0;

		scanf("%d", &n);
		stones[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &stones[i]);
		scanf("%d", &jump);

		int flg = false;

		for (int i = 0; i <= n;) {
			for (int j = i + 1; j <= n; j++) {
				if (stones[j] - stones[i] > jump) {
					if (j == i + 1) {
						Answer = -1;
						flg = true;
					}
					else {
						Answer++;
						i = j - 1;
					}
					break;
				}
				else if (j == n) {
					Answer++;
					flg = true;
					break;
				}
			}
			if (flg)
				break;
		}
		

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}

	return 0;
}