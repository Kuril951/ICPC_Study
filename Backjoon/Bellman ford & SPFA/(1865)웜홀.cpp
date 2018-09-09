#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

#define pii pair<int, int>
#define INF 200000000
#define MAX_V 2501

using namespace std;

vector<pii> adj[MAX_V];

void SPFA(int N)
{
	queue<int> Q;
	int inQ[MAX_V] = { 0 };
	int dist[MAX_V];

	fill(dist, dist + N + 1, INF);
	dist[1] = 0;
	Q.push(1);

	while (!Q.empty()) {
		int qsize = Q.size();
		while (qsize--) {
			int cur = Q.front();
			Q.pop();
			inQ[cur] = false;

			for (auto &node : adj[cur]) {
				int next = node.first, d = node.second;
				if (dist[next] > dist[cur] + d) {
					dist[next] = dist[cur] + d;
					if (!inQ[next]) {
						Q.push(next);
						inQ[next] = true;
						if (next == 1) {
							printf("YES\n");
							return;
						}
					}
				}
			}
		}
	}
	printf("NO\n");
	return;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int N, M, W;
		int v, u, w;
		scanf("%d %d %d", &N, &M, &W);
		// µµ·Î
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d", &v, &u, &w);
			adj[v].push_back({ u, w });
			adj[u].push_back({ v, w });
		}
		// ¿úÈ¦
		for (int j = 0; j < W; j++) {
			scanf("%d %d %d", &v, &u, &w);
			adj[v].push_back({ u, -w });
		}

		SPFA(N);

		for (int i = 0; i < M + W; i++)
			adj[i].clear();
	}
	return 0;
}