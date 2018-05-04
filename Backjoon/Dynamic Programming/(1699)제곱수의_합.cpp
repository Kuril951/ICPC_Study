#include<iostream>
#include<cmath>
#include<memory.h>

using namespace std;

int N;
int dp[100001];
int root;

int func(int n)
{
    if(n > N)
        return 1000000;
    if (n == N)
        return 0;

    int &ret = dp[n];

    if(ret != -1)
        return ret;

    ret = 1000000;

    for(int i = root; i>0; i--)
        ret = min(ret, func(n + (i * i)));

    return ++ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%d",&N);
    root = (int)ceil(sqrt(N));
    printf("%d\n", func(0));
    return 0;
}