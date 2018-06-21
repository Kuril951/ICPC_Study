#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<functional>
#include<cstring>

#define MAX_V 150000
#define ll long long
#define pll pair<ll, int>

using namespace std;

ll dist[MAX_V];
bool visited[MAX_V] = { 0 };
int nearest[MAX_V] = { 0 };
vector<pll> adj[MAX_V];
priority_queue<pll, vector<pll>, greater<pll>> pq;

inline void solve()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < MAX_V; i++)
		adj[i].clear();

	while (!pq.empty())
		pq.pop();

	memset(visited, 0, sizeof(visited));
	memset(nearest, 0, sizeof(nearest));
	fill(dist, dist + MAX_V, LLONG_MAX);

	for (int i = 0; i < M; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld",&a,&b,&c);
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	for (int i = 0; i < K; i++) {
		int a;
		scanf("%d",&a);
		dist[a] = 0;
		pq.push({ 0, a });
		nearest[a] = a;
	}

	//다익스트라
	while (!pq.empty())
	{
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && visited[curr]);

		if (visited[curr])
			break;

		visited[curr] = true;

		for (auto &p : adj[curr]) {
			int next = p.first, d = p.second;
			if (dist[next] == dist[curr] + d)
			    nearest[next] = min(nearest[next], nearest[curr]);
			if (dist[next] > dist[curr] + d) {
				dist[next] = dist[curr] + d;
				pq.push({ dist[next], next });
				nearest[next] = nearest[curr];
			}
		}
	}
	ll sum1 = 0, sum2 = 0;
	for (int i = 1; i <= N; i++) {
		sum1 += dist[i];
		sum2 += nearest[i];
	}

	printf("%lld\n%lld\n", sum1, sum2);
}

int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d",&T);
	for (test_case = 0; test_case < T; test_case++)
	{
		printf("Case #%d\n",test_case + 1);
		solve();
	}

	return 0;//Your program should return 0 on normal termination.
}