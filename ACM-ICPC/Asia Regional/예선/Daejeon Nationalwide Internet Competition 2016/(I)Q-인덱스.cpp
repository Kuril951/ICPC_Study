#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int paper[1001];

int main()
{
	int n;

	cin >> n;

	for(int i=0; i<n; i++)
		scanf("%d",&paper[i]);

	sort(paper, paper + n);

	if(paper[n - 1] == 0)
		printf("0");
	else {
		for(int i=0; i<n; i++) {
			if(n - i <= paper[i]) {
				printf("%d", n - i);
				break;
			}
		}
	}

	return 0;
}
