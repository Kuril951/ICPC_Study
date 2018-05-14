#include <iostream>
#include <memory.h>

using namespace std;

int Answer, N;
int room[1001][1001];
int isVisited[1001][1001];

//  0: x, 1: /, 2: \
// u r d l : 0 1 2 3
int ref1[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //x y
int ref2[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; //x y
int gogo[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; //x y
int main(int argc, char** argv)
{
    int T, test_case;

    scanf("%d",&T);
    for(test_case = 0; test_case  < T; test_case++)
    {
        memset(isVisited, 0 ,sizeof(isVisited));
        Answer = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%1d", &room[i][j]);

        int x = 0, y = 0, way = 3, cnt = 0;
        while(1)
        {
            if(x < 0 || y < 0 || x>= N || y >= N)
                break;
            if(room[y][x] == 0){
                x += gogo[way][0];
                y += gogo[way][1];
            }
            else if(room[y][x] == 1){
                if(!isVisited[y][x]){
                    cnt++;
                    isVisited[y][x] = 1;
                }
                x += ref1[way][0];
                y += ref1[way][1];
                way = (way / 2) * 2 + !(way % 2);
            }
            else{
                if(!isVisited[y][x]){
                    cnt++;
                    isVisited[y][x] = 1;
                }
                x += ref2[way][0];
                y += ref2[way][1];
                way = !(way / 2) * 2 + !(way % 2);
            }
        }

        printf("Case #%d\n", test_case + 1);
        printf("%d\n", cnt);
    }

    return 0;
}