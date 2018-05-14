#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> num;

int main()
{
    int N, t;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        num.push_back(tmp);
    }

    sort(num.begin(), num.end());

    scanf("%d",&t);
    for(int i=0; i<t; i++){
        int tmp;
        scanf("%d", &tmp);
        auto it = lower_bound(num.begin(), num.end(), tmp);
        if(it != num.end()){
            if(*it == tmp)
                printf("1\n");
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }

    return 0;
}