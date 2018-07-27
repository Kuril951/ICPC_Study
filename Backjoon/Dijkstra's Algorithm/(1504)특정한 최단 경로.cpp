#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>

#define MAX_V 801
#define pii pair<int, int>
#define ll long long

using namespace std;

int N, E;

vector<pii> adj[MAX_V];

int dijkstra(int s, int e)
{
    int dist[MAX_V];
    fill(dist, dist + MAX_V, INT_MAX);
    bool visited[MAX_V] = { 0 };
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    int prev[MAX_V];
    fill(prev, prev + MAX_V, -1);

    dist[s] = 0;
    PQ.push({0, s});

    while(!PQ.empty()){
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]);

        if(visited[curr])
            break;

        visited[curr] = true;
        for(auto &p : adj[curr]){
            int next = p.first, d = p.second;
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                prev[next] = curr;
                PQ.push({dist[next], next});
            }
        }
    }
    if(dist[e] == INT_MAX)
        return -1;
    return dist[e];
}

int main()
{
    scanf("%d %d", &N, &E);
    for(int i=0; i<E; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    int m1, m2;
    scanf("%d %d", &m1, &m2);

    int route1[4] = {1, m1, m2, N};
    int route2[4] = {1, m2, m1, N};
    ll r1=0, r2=0;


    for(int i=0; i<3; i++) {
        int tmp = dijkstra(route1[i], route1[i + 1]);
        if(tmp == -1){
            printf("-1");
            return 0;
        }
        r1 += tmp;
    }
    for(int i=0; i<3; i++) {
        int tmp = dijkstra(route2[i], route2[i + 1]);
        if(tmp == -1){
            printf("-1");
            return 0;
        }
        r2 += tmp;
    }

    printf("%lld", min(r1, r2));

    return 0;
}