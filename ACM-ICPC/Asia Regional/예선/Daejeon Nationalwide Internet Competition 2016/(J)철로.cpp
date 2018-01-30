#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define sz(v) ((int)(v).size())

int N, L;

struct Z{
    int a, b;
} A[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++){
        scanf("%d%d", &A[i].a, &A[i].b);
        if (A[i].a > A[i].b) swap(A[i].a, A[i].b);
    }
    scanf("%d", &L);
    sort(A+1, A+N+1, [](const Z &a, const Z &b){
        return a.b < b.b;
    });
    priority_queue <int> que;
    int ans = 0;
    for (int i=1;i<=N;i++){
        que.push(-A[i].a);
        while (!que.empty() && -que.top() < A[i].b-L) que.pop();
        ans = max(ans, sz(que));
    }
    printf("%d\n", ans);
}
