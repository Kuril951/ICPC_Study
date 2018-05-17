#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<climits>
#include<algorithm>

#define MAX_V 20001

using namespace std;

typedef pair<int, int> pii;

int main()
{
	int V, E, K;
	vector<pii> adj[MAX_V];

	scanf("%d %d %d", &V, &E, &K);
	
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b, c });
	}

	int dist[MAX_V];
	fill(dist, dist + MAX_V, INT_MAX);
	bool isVisited[MAX_V] = { 0 };
	priority_queue<pii, vector<pii>, greater<pii>> PQ;

	dist[K] = 0;
	PQ.push(pii(0, K));

	while (!PQ.empty()) {
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && isVisited[curr]);	//방문했던 정점이 아닐때까지 뽑기
		
		if (isVisited[curr])
			break;

		isVisited[curr] = true;
		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;
			
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				PQ.push(pii(dist[next], next));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}