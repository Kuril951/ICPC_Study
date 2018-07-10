#include<iostream>
#include <vector>

using namespace std;

/*
6 4
1 1 1 0
1 2 2 0
1 0 0 1
0 0 0 1
0 0 0 3
0 0 0 3

 * */

int func(vector<vector<int>> &pic, int y, int x, int m ,int n, int color)
{
    pic[y][x] = 0;
    int ret = 1;
    if(y - 1 >= 0 && pic[y - 1][x] == color)
        ret += func(pic, y - 1, x, m, n, color);
    if(x + 1 < n && pic[y][x + 1] == color)
        ret += func(pic, y, x + 1, m, n, color);
    if(y + 1 < m && pic[y + 1][x] == color)
        ret += func(pic, y + 1, x, m, n, color);
    if(x - 1 >= 0 && pic[y][x - 1] == color)
        ret += func(pic, y, x - 1, m, n, color);

    return ret;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;


    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j]){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, func(picture, i, j, m, n, picture[i][j]));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    int m, n;

    cin >> m >> n;

    vector<vector<int>> picture;
    picture.resize(m);
    for(int i=0; i<m; i++)
        picture[i].assign(n, 0);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            scanf("%d", &picture[i][j]);
    }

    vector<int> ans = solution(m, n, picture);

    printf("%d %d",ans[0], ans[1]);

    return 0;
}
