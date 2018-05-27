#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

pair<int, int> line[1000001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		line[i].first = a;
		line[i].second = b;
	}

	sort(line, line + N);

	int s = INT_MIN, e = INT_MIN, length = 0;
	for (int i = 0; i < N; i++)
	{
		if (e < line[i].first) {
			length += e - s;
			s = line[i].first;
			e = line[i].second;
		}
		else
			e = max(e, line[i].second);
	}

	printf("%d", length + e - s);

	return 0;
}