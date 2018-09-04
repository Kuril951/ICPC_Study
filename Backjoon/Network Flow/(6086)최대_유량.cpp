#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<climits>

#define MAX_N 1001

using namespace std;

int Alpa2int(char ch) {
	if ('A' <= ch && ch <= 'Z')
		return ch - 'A';
	return ch - 'a' + 26;
}

int main()
{
	int c[MAX_N][MAX_N] = { 0 }, f[MAX_N][MAX_N] = { 0 };
	vector<int> adj[MAX_N];
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		getchar();
		char u, v;
		int w;
		scanf("%c %c %d", &u, &v, &w);
		int uI = Alpa2int(u), vI = Alpa2int(v);
		adj[uI].push_back(vI);
		adj[vI].push_back(uI);
		c[uI][vI] = c[vI][uI] += w;
	}

	int S = Alpa2int('A'), E = Alpa2int('Z'), res = 0;

	while (1) {
		int prev[MAX_N];
		memset(prev, -1, sizeof(prev));
		queue<int> Q;

		Q.push(S);

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (auto next : adj[curr]) {
				if (prev[next] == -1 && c[curr][next] - f[curr][next] > 0) {
					Q.push(next);
					prev[next] = curr;
					if (next == E)
						break;
				}
			}
		}

		// 싱크로 가능 경로 없음
		if (prev[E] == -1)
			break;

		int minFlow = INT_MAX;
		for (int i = E; i != S; i = prev[i]) {
			minFlow = min(minFlow, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += minFlow;
			f[i][prev[i]] -= minFlow;
		}

		res += minFlow;

	}
	printf("%d", res);
	return 0;
}