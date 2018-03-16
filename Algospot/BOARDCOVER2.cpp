#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_SIZE 10

using namespace std;

char board[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> block[4];		// y, x
int isDup[4];		//중복확인
int blockCnt;		//블럭 크기
int H, W, blockH, blockW;		//보드, 블럭
int maxBlockCnt;

void show(int y, int x)
{
	printf("(%d, %d)\n", y, x);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}
}

void rotateBlock(int blockIdx, int &h, int &w)
{
	if (blockIdx % 2)
		swap(h, w);
}

void initBlock()
{
	for (int i = 0; i < 3; i++) {
		int bH = blockH, bW = blockW;
		rotateBlock(i + 1, bH, bW);
		for (auto bIdx : block[i])
			block[i + 1].push_back(make_pair(bIdx.second, bW - bIdx.first - 1));
		sort(block[i + 1].begin(), block[i + 1].end());
	}

	isDup[0] = 0;

	for (int i = 1; i < 4; i++) {
		for (int j = 0; j < blockCnt; j++)
			if (block[0][j] != block[i][j])
				isDup[i] = 0;
	}

}

bool putBlock(int i, int y, int x)
{
	for (auto bIdx : block[i])
		if (y + bIdx.first >= H || x + bIdx.second >= W ||
			board[y + bIdx.first][x + bIdx.second] == '#')
			return false;
	return true;
}

void boardCover2(int y, int x, int putBlockCnt, int emptyBoardCnt)
{
	//show(y, x);

	if (y == H || y > H - min(blockH, blockW)) {
		maxBlockCnt = max(maxBlockCnt, putBlockCnt);
		return;
	}
	if (emptyBoardCnt / blockCnt + putBlockCnt <= maxBlockCnt)
		return;

	// 블럭 탐색할 좌표
	int nextX = x + 1, nextY = y;

	if (nextX == W) {
		nextY = y + 1;
		nextX = 0;
	}

	for (int i = 0; i < 4 && !isDup[i]; i++) {
		// 블럭을 놓을수 있는지 확인
		if (putBlock(i, y, x)) {
			for (auto bIdx : block[i])
				board[y + bIdx.first][x + bIdx.second] = '#';
			boardCover2(nextY, nextX, putBlockCnt + 1, emptyBoardCnt - blockCnt);
			for (auto bIdx : block[i])
				board[y + bIdx.first][x + bIdx.second] = '.';
		}
	}
	boardCover2(nextY, nextX, putBlockCnt, emptyBoardCnt - (board[y][x] == '.'));
}

int main()
{
	int T;
	char tmp;

	scanf("%d", &T);

	while (T--)
	{
		int emptyBoardCnt = 0;
		for (int i = 0; i < 4; i++) {
			block[i].clear();
			isDup[i] = 1;
		}
		blockCnt = 0;
		maxBlockCnt = 0;

		scanf("%d %d %d %d", &H, &W, &blockH, &blockW);
		getchar();
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%c", &board[i][j]);
				if (board[i][j] == '.')
					emptyBoardCnt++;
			}
			getchar();
		}
		for (int i = 0; i < blockH; i++) {
			for (int j = 0; j < blockW; j++) {
				scanf("%c", &tmp);
				if (tmp == '#') {
					block[0].push_back(make_pair(i, j));
					blockCnt++;
				}
			}
			getchar();
		}

		initBlock();

		boardCover2(0, 0, 0, emptyBoardCnt);

		printf("%d\n", maxBlockCnt);
	}

	return 0;
}