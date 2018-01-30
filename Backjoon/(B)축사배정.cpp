#include<iostream>
#include<algorithm>
#include<queue>
#include<climits>

#define MAX_V 402

using namespace std;

int main()
{
	int N, M;
	int c[MAX_V][MAX_V] = { 0 };
	int f[MAX_V][MAX_V] = { 0 };
	vector<int> adj[MAX_V];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 0; j < cnt; j++) {
			int tmp;
			scanf("%d", &tmp);
			c[i + 1][tmp + 200] = 1;
			adj[i + 1].push_back(tmp + 200);
			adj[tmp + 200].push_back(i + 1);
		}
	}

	int S = 0, E = MAX_V - 1, res = 0;

	for (int i = 1; i <= N; i++) {
		c[S][i] = 1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for (int i = 201; i <= M + 200; i++) {
		c[i][E] = 1;
		adj[E].push_back(i);
		adj[i].push_back(E);
	}

	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();

			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					prev[next] = curr;
					Q.push(next);
					if (next == E) break;
				}
			}
		}

		if (prev[E] == -1) break;

		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += 1;
			f[i][prev[i]] -= 1;
		}
		res++;
	}

	printf("%d", res);

	return 0;
}