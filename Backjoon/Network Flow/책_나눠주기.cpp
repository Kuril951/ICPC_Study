// �̺� ��Ī
#include<iostream>
#include<vector>
#include<memory.h>

#define MAX_V 1001

using namespace std;

int N, M;		// N: å �� , M: �л� ��
int A[MAX_V], B[MAX_V];		// A: �л� , B: å
vector<int> adj[MAX_V];
bool isVisited[MAX_V];

bool dfs(int idx)
{
	isVisited[idx] = true;

	for (int bookIdx : adj[idx]) {
		// å�� ����ų�
		// ���� å�� �������ִ� ����� �ٸ� å�� �޾Ƶ� �Ǵ� ���
		if (B[bookIdx] == -1 || (!isVisited[B[bookIdx]] && dfs(B[bookIdx]))) {
			A[idx] = bookIdx;
			B[bookIdx] = idx;
			return true;
		}
	}
	// ��Ī ����
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