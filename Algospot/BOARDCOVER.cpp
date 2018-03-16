#include<iostream>
#include<memory.h>

using namespace std;

int T;
int H, W;		//너비 높이
char map[21][21];
int cnt;

void func(int x, int y, int emptyBlockCnt)
{
	if (emptyBlockCnt < 3) {
		if (emptyBlockCnt == 0)	cnt++;
		return;
	}
	else if (x == W - 1 && H == H - 1)
		return;
	int nextX, nextY;
	if (x == W - 1) {
		nextX = 0;
		nextY = y + 1;
	}
	else {
		nextX = x + 1;
		nextY = y;
	}
	if (map[y][x] == '.'){	
		if (map[y][x + 1] == '.' && map[y + 1][x] == '.') {
			map[y][x] = map[y][x + 1] = map[y + 1][x] = '#';
			func(nextX, nextY, emptyBlockCnt - 3);
			map[y][x] = map[y][x + 1] = map[y + 1][x] = '.';
		}
		if (map[y][x + 1] == '.' && map[y + 1][x + 1] == '.') {
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = '#';
			func(nextX, nextY, emptyBlockCnt - 3);
			map[y][x] = map[y][x + 1] = map[y + 1][x + 1] = '.';
		}
		if (map[y + 1][x] == '.' && map[y + 1][x + 1] == '.') {
			map[y][x] = map[y + 1][x] = map[y + 1][x + 1] = '#';
			func(nextX, nextY, emptyBlockCnt - 3);
			map[y][x] = map[y + 1][x] = map[y + 1][x + 1] = '.';
		}
		if (map[y + 1][x] == '.' && map[y + 1][x - 1] == '.') {
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = '#';
			func(nextX, nextY, emptyBlockCnt - 3);
			map[y][x] = map[y + 1][x] = map[y + 1][x - 1] = '.';
		}
	}
	else if(map[y][x] == '#'){
		func(nextX, nextY, emptyBlockCnt);
	}
}


int main()
{
	scanf("%d", &T);

	while (T--)
	{
		int emptyBlockCnt = 0;
		cnt = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d", &H, &W);

		for (int i = 0; i < H; i++) {
			getchar();
			for (int j = 0; j < W; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '.')
					++emptyBlockCnt;
			}
		}

		if (emptyBlockCnt % 3) printf("0\n");
		else {
			func(0, 0, emptyBlockCnt);
			printf("%d\n", cnt);
		}

	}


	return 0;
}