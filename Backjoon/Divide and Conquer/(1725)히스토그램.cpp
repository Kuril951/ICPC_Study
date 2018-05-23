#include<iostream>

using namespace std;

int N;
int board[65][65];

int isPureBlock(int x, int y, int blockSize)
{
    int bflg = false, wflg = false;
    for(int i=0; i<blockSize; i++){
        for(int j=0; j<blockSize; j++) {
            if (board[y + i][x + j])
                bflg = true;
            else
                wflg = true;

            if(bflg && wflg)
                return -1;
        }
    }

    if(bflg)
        return 1;
    else
        return 0;
}

void quadTree(int x, int y, int blockSize)
{
    int color;
    if((color = isPureBlock(x, y, blockSize)) != -1){
        printf("%d", color);
        return;
    }

    printf("(");
    int subBlockSize = blockSize / 2;
    int pos[4][2] = {{x, y}, {x + subBlockSize, y},
                     {x, y + subBlockSize}, {x + subBlockSize, y + subBlockSize}};
    for(int i=0; i<4; i++) {
        int color = 0;
        if((color = isPureBlock(pos[i][0], pos[i][1], subBlockSize)) != -1)
            printf("%d", color);
        else {
            quadTree(pos[i][0], pos[i][1], subBlockSize);
        }
    }
    printf(")");
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%1d", &board[i][j]);

    quadTree(0, 0, N);

    return 0;
}