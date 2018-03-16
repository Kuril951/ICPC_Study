// 이분 매칭
#include<iostream>
#include<vector>
#include<memory.h>

#define MAX_V 1001

using namespace std;

int N, M;		// N: 책 수 , M: 학생 수
int A[MAX_V], B[MAX_V];		// A: 학생 , B: 책
vector<int> adj[MAX_V];
bool isVisited[MAX_V];

bool dfs(int idx)
{
	isVisited[idx] = true;

	for (int bookIdx : adj[idx]) {
		// 책을 안줬거나
		// 먼저 책을 가지고있던 사람이 다른 책을 받아도 되는 경우
		if (B[bookIdx] == -1 || (!isVisited[B[bookIdx]] && dfs(B[bookIdx]))) {
			A[idx] = bookIdx;
			B[bookIdx] = idx;
			return true;
		}
	}
	// 매칭 실패
	return false;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		memset(A, -1, sizeof(A));
		memset(B, -1, sizeof(B));

		for (int i = 0; i < MAX_V; i++)
			adj[i].clear();

		scanf("%d %d", &N, &M);

		for (int i = 1; i <= M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			for (int j = a; j <= b; j++)
				adj[i].push_back(j);
		}
		int total = 0;

		for (int i = 1; i <= M; i++) {
			if (A[i] == -1) {
				memset(isVisited, 0, sizeof(isVisited));
				if (dfs(i))
					total++;
			}
		}

		printf("%d\n", total);
	}

	return 0;
}