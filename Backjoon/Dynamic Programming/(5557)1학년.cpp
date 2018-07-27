#include<iostream>
#include<cstring>

#define ll long long

using namespace std;

int N;
int num[101];
ll dp[101][2001];

ll func(int idx, int s)
{
    if(idx == N - 1){
        if(s == num[idx])
            return 1;
        return 0;
    }

    ll &ret = dp[idx][s];
    if(ret != -1)
        return ret;
    ret = 0;

    if(s + num[idx] <= 20)
        ret += func(idx + 1, s + num[idx]);
    if(s - num[idx] >= 0)
        ret += func(idx + 1, s - num[idx]);

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&num[i]);

    printf("%lld", func(1, num[0]));
    return 0;
}