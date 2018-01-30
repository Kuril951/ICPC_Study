#include<iostream>
#include<vector>
#include<queue>

#define MAX_CITY 1001
#define CITY 500

using namespace std;


int main()
{
	int c[MAX_CITY][MAX_CITY] = { 0 };
	int f[MAX_CITY][MAX_CITY] = { 0 };
	vector<int> adj[MAX_CITY];

	int n, p;

	scanf("%d %d", &n, &p);

	for (int i = 3; i <= n; i++) {
		c[i][CITY + i] = 1;
		adj[i].push_back(CITY + i);
		adj[CITY + i].push_back(i);
	}

	for (int i = 0; i < p; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		
		c[CITY + u][v] = c[CITY + v][u] = 1;
		if (v != 1 && u != 2) {
			adj[CITY + u].push_back(v);
			adj[v].push_back(CITY + u);
		}
		if (u != 1 && v != 2) {
			adj[CITY + v].push_back(u);
			adj[u].push_back(CITY + v);
		}
	}

	int total = 0, S = CITY + 1, E = 2;
	while (1)
	{
		int prev[MAX_CITY];
		fill(prev, prev + MAX_CITY, -1);

		queue<int> Q;
		Q.push(S);

		while (!Q.empty())
		{
			int curr = Q.front();
			Q.pop();

			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					prev[next] = curr;
					Q.push(next);
					if (next == E)
						break;
				}
			}
		}

		if (prev[E] == -1)
			break;

		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i]++;
			f[i][prev[i]]--;
		}
		total++;
	}

	printf("%d", total);

	return 0;
}