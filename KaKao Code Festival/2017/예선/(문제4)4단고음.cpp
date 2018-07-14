#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<pair<int, int>, int> dp;

int func(int N, int plusCnt, int starMaxCnt)
{
    if(plusCnt > starMaxCnt * 2)
        return 0;
    if(N == 1 && plusCnt == 0)
        return 1;
    if(N <= 1)
        return 0;

    if(dp.count({N, plusCnt}))
        return dp[{N, plusCnt}];

    int &ret = dp[{N, plusCnt}];

    if(plusCnt >= 2 && N % 3 == 0)
        ret += func(N / 3, plusCnt - 2, starMaxCnt);
    ret += func(N - 1, plusCnt + 1, starMaxCnt);

    return ret;
}

int solution(int n) {
    int threeCnt = 0;
    int tmp = n;

    while (tmp / 3) {
        tmp /= 3;
        threeCnt++;
    }
    int answer = func(n, 0, threeCnt);
    return answer;
}

int main()
{
    int N;
    scanf("%d", &N);
    printf("%d", solution(N));
}
