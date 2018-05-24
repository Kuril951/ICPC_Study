#include<iostream>

using namespace std;

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        int a, b, x;
        scanf("%d %d", &a, &b);

        while(a) {
            x = (b - 1) / a + 1;
            a = a * x - b;
            b *= x;
        }

        printf("%d\n", b);

    }

    return 0;
}