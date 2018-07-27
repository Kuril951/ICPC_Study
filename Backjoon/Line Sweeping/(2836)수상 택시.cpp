#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d",&a, &b);
        if(a > b)
            v.emplace_back(make_pair(b, a));
    }

    sort(v.begin(), v.end());

    int s = 0, e = 0;
    long long res = 0;
    for(int i=0; i<v.size(); i++){
        if(e < v[i].first){
            res += (e - s) * 2;
            s = v[i].first;
            e = v[i].second;
        }
        else if(e < v[i].second)
            e = v[i].second;
    }
    res += (e - s) * 2 + M;
    printf("%lld", res);
    return 0;
}