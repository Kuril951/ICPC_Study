#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
#include<functional>

#define INF 10000000
#define pii pair<int, int>

using namespace std;

int N, M, X;
vector<pair<int, int>> adj[10001];

int dfs(int dist[], bool flg, int S)
{
	fill(dist, dist + 10001, INF);
	bool visited[10001] = { 0 };
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr]);

		if (flg && curr == X)
			return dist[curr];
		if (visited[curr])
			break;

		visited[curr] = true;

		for (auto node : adj[curr]) {
			int next = node.first, d = node.second;
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push({ dist[next], next });
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= N; i++)
		res = max(res, dist[i]);
	return res;
}

int main()
{
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}
	
	int dist[10001], dist2[10001];
	int res = 0;

	dfs(dist, false, X);
	for (int i = 1; i <= N; i++)
		res = max(res, dfs(dist2, true, i) + dist[i]);

	printf("%d", res);

	return 0;
}