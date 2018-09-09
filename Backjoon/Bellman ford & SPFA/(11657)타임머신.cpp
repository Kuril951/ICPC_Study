#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>

#define pii pair<int, int>
#define INF 100000000
#define MAX_V 501

using namespace std;

int main()
{
	int N, M, dist[MAX_V];
	int u, v, w;
	vector<pii> adj[MAX_V];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &u, &v, &w);
		adj[u - 1].push_back({ v - 1, w });
	}

	queue<int> Q;
	fill(dist, dist + N, INF);
	dist[0] = 0;
	Q.push(0);

	bool inQ[MAX_V] = { 0 };
	int cnt[MAX_V] = { 1, 0 };
	// SPFA
	while(!Q.empty()){
		int cur = Q.front();
		inQ[cur] = false;
		Q.pop();

		for (auto &node : adj[cur]) {
			int next = node.first, w = node.second;
			if (dist[next] > dist[cur] + w) {
				dist[next] = dist[cur] + w;
				if (inQ[next] == false) {
					Q.push(next);
					inQ[next] = true;
					if (cnt[next]++ == N) {
						printf("-1");
						return 0;
					}
				}
			}
		}
	}

	for (int i = 1; i < N; i++)
		printf("%d\n", dist[i] != INF ? dist[i] : -1);

	return 0;
}