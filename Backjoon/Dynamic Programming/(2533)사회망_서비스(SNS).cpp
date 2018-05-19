#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<int> adj[1000001];
int cnt = 0;

bool func(int idx, int prev)
{
    if(adj[idx].size() == 1 && adj[idx][0] == prev)
        return false;

    bool flg = false;

    for(auto next : adj[idx]){
        if(next != prev && !func(next, idx))
            flg = true;
    }
    if(flg)
        cnt++;
    return flg;
}

int main()
{
    scanf("%d",&N);

    for(int i=0; i<N - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    func(1, -1);
    printf("%d", cnt);

    return 0;
}