#include<iostream>
#include<memory.h>

#define MOD 1000000000

using namespace std;

int N, K;
int dp[201][201];

int func(int n, int k)
{
    if(n > N || k > K)
        return 0;
    if(N == n)
        return 1;
    
    int &ret = dp[n][k];
    if(ret != -1)
        return ret;
    ret = 0;

    for(int i=0; i<= N; i++)
        ret = (ret + func(n + i, k + 1)) % MOD;

    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d %d",&N,&K);

    printf("%d", func(0, 0));

    return 0;
}