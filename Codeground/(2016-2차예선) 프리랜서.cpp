#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int Answer;
int A[10001], B[10001];
int dp[10001];

int main(int argc, char** argv)
{
    int T, test_case;

    scanf("%d",&T);
    for(test_case = 0; test_case  < T; test_case++)
    {
        int N;
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(dp, 0, sizeof(dp));

        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d",&A[i]);
        for(int i=0; i<N; i++)
            scanf("%d",&B[i]);

        dp[0] = max(A[0], B[0]);
        dp[1] = max(dp[0] + A[1], B[1]);
        for(int i=2; i<N; i++){
            dp[i] = max(dp[i - 1] + A[i], dp[i - 2] + B[i]);
        }

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", dp[N - 1]);
    }

    return 0;
}
