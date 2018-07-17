#include<iostream>
#include<string>
#include<vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> tree[10010], isUsed;
int w[10010], dp[10010][2];

void trace(int curr, int isPrevSelected)
{
    if(isPrevSelected)
        for(auto next : tree[curr])
            trace(next, 0);
    else { // 이전 노드 사용 안함
        for(auto next : tree[curr]){
            if(dp[next][1] < dp[next][0]){  //현재 노드 사용 안함
                isUsed.push_back(next);
                trace(next, 1);
            }
            else
                trace(next, 0);
        }
    }
}

int func(int node, bool isPrevSelected)
{
    int &ret = dp[node][isPrevSelected];
    if(ret != -1)
        return ret;
    ret = 0;

    int a = isPrevSelected ? 0 : w[node], b = 0;
    for(auto next : tree[node]){
        if(!isPrevSelected)
            a += func(next, true);
        b += func(next, false);
    }
    ret = max(a, b);

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++)
        scanf("%d", &w[i]);

    for(int i=0; i<N - 1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a < b)
            tree[a].push_back(b);
        else
            tree[b].push_back(a);
    }
    tree[0].push_back(1);
    printf("%d\n", func(0, false));
    trace(0, 0);
    sort(isUsed.begin(), isUsed.end());
    for(auto node : isUsed)
        printf("%d ", node);


    return 0;
}
