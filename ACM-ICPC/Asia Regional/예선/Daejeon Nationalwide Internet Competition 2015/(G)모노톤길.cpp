#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


typedef struct {
	int x, y;
}Cafe;

Cafe cafe[100001];
int pos[11];

bool cmpX(Cafe a, Cafe b) { return a.x < b.x; }
bool cmpY(Cafe a, Cafe b) { return a.y < b.y; }
bool cmpY2(Cafe a, Cafe b) { return a.y > b.y; }

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int a, b;
		for (int i=0; i<N; i++)
			scanf("%d %d", &cafe[i].x, &cafe[i].y);
		int N2;
		cin >> N2;
		for (int i=0; i<N2; i++)
			scanf("%d", &pos[i]);

		sort(cafe, cafe+N, cmpX);


		int beforeX=0;
		int startIdx = 0;
		int cnt=0;
		bool chk=false;
		for (int i=1; i<N; i++) {

			if (beforeX == cafe[i].x) {
				if (!chk) // 바뀐 처음일 경우
					startIdx = i-1;
				chk = true;
			}

			else {
				beforeX = cafe[i].x;
				if (chk) {

					sort(cafe+startIdx, cafe+i, cmpY); // start ~ i-1

					if (cafe[startIdx-1].y != cafe[startIdx].y)
						sort(cafe+startIdx, cafe+i, cmpY2);
				}
				chk = false;
			}


		}
		sort(cafe+startIdx, cafe+N, cmpY); // start ~ i-1

		if (cafe[startIdx-1].y != cafe[startIdx].y)
			sort(cafe+startIdx, cafe+N, cmpY2);


		for (int i=0; i<N2; i++)
			printf("%d %d\n", cafe[pos[i]-1].x, cafe[pos[i]-1].y);

	}

	return 0;
}
