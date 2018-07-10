#include <vector>
#include<iostream>
#include<cstring>

using namespace std;

int MOD = 20170805;

int dp[501][501];

int func(vector<vector<int>> &cm, int y, int x, int m, int n, int way)
{
    if(y < 0 || y >= m || x < 0 || x >= n || cm[y][x] == 1)
        return 0;
    if(y == m - 1 && x == n - 1)
        return 1;

    //way 0 위 -> 아래  1 : 왼 -> 오른
    if(cm[y][x] == 2){
        int ret = 0;
        if(way == 0)
            ret = (ret + func(cm, y + 1, x, m, n, way)) % MOD;
        else
            ret = (ret + func(cm, y, x + 1, m, n, way)) % MOD;
        return ret;
    }
    else{
        int &ret = dp[y][x];
        if(ret != -1)
            return ret;
        ret = 0;
        ret = (ret + func(cm, y + 1, x, m, n, 0)) % MOD;
        ret = (ret + func(cm, y, x + 1, m, n, 1)) % MOD;

        return ret;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, -1, sizeof(dp));
    int answer = func(city_map, 0, 0, m, n, 0);

    return answer;
}

int main()
{
    int m, n;
    vector<vector<int>> cm;

    cin >> m >> n;
    cm.resize(m);
    for(int i=0; i<m; i++)
        cm[i].assign(n, 0);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> cm[i][j];
    auto a = solution(m, n, cm);

    printf("%d", a);
}
