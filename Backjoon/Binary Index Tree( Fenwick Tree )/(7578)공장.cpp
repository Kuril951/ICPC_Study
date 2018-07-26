#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

#define ll long long

using namespace std;

int N, tree[500002];
int num[500002];
map<int, int> fac;

void update(int i)
{
    while(i <= N){
        tree[i]++;
        i += (i & -i);
    }
}

int sum(int i)
{
    int ret = 0;
    while(i > 0){
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}


int main()
{
    int tmp;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &num[i]);
    for(int i=1; i<=N; i++){
        scanf("%d", &tmp);
        fac[tmp] = i;
    }

    ll cnt = 0;
    for(int i=1; i<=N; i++){
        cnt += (ll)sum(N) - (ll)sum(fac[num[i]]);
        update(fac[num[i]]);
    }
    printf("%lld", cnt);

    return 0;
}