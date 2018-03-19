#include<iostream>
#include<vector>

using namespace std;

void maze(int n, int dstL, int x = 1, int y = 1, vector<int> order = { 0, 1, 3, 2 })
{
	if (dstL < 1 || dstL > n*n)
		return;

	if (n == 1) {
		printf("%d %d", x, y);
		return;
	}

	int h = n / 2, size = h *  h;

	maze(h, dstL, x + (order[0] & 2) / 2 * h, y + (order[0] & 1)*h, {order[0],order[3], order[2], order[1]});
	maze(h, dstL - size, x + (order[1] & 2) / 2 * h, y + (order[1] & 1)*h, order);
	maze(h, dstL - size * 2, x + (order[2] & 2) / 2 * h, y + (order[2] & 1)*h, order);
	maze(h, dstL - size * 3, x + (order[3] & 2) / 2 * h, y + (order[3] & 1)*h, { order[2],order[1], order[0], order[3]});
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	maze(n, m);

	return 0;
}