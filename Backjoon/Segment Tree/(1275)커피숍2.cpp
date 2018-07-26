#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define ll long long

using namespace std;

int N, Q;
ll num[100001];
vector<ll> tree(1 << (int)ceil((log2(100000) + 1)), 0);

void update(int node, int nL, int nR, int idx, ll diff)
{
    if(idx < nL || nR < idx) return;
    tree[node] += diff;
    if(nL != nR){
        int mid = (nL + nR) / 2;
        update(node * 2, nL, mid, idx, diff);
        update(node * 2 + 1, mid + 1, nR, idx, diff);
    }
}

ll sum(int node, int nL, int nR, int s, int e)
{
    if(e < nL || nR < s) return 0;
    if(s <= nL && nR <= e) return tree[node];
    int mid = (nL + nR) / 2;
    return sum(node * 2, nL, mid, s, e) + sum(node * 2 + 1, mid + 1, nR, s, e);
}


int main()
{
    scanf("%d %d",&N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%lld", &num[i]);
        update(1, 0, N-1, i, num[i]);
    }

    for(int i=0; i<Q; i++){
        int a, b, c;
        ll d;
        scanf("%d %d %d %lld",&a, &b, &c, &d);
        if(a > b)
            swap(a, b);
        printf("%lld\n", sum(1, 0, N-1, a - 1, b - 1));
        update(1, 0, N-1, c - 1, d - num[c - 1]);
        num[c - 1] = d;
    }
}