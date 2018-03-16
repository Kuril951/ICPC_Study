#include<iostream>
#include<vector>
#include<memory.h>

#define MAX_V 2002

using namespace std;

int person[MAX_V], task[MAX_V];
vector<int> adj[MAX_V];
int isVisited[MAX_V];

bool dfs(int idx)
{
	isVisited[idx] = true;

	for (int tIdx : adj[idx]) {
		if (!task[tIdx] || (!isVisited[task[tIdx]] && dfs(task[tIdx]))) {
			person[idx] = tIdx;
			task[tIdx] = idx;
			return true;
		}
	}
	return false;
}

int main()
{
	int N, M;	// N: 직원 수, M: 일 수

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			adj[2 * i].push_back(tmp);
			adj[2 * i + 1].push_back(tmp);
		}
	}

	int total = 0;
	
	for (int i = 1; i < 2*(N + 1); i++) {
		if (!person[i]) {
			memset(isVisited, 0, sizeof(isVisited));
			if (dfs(i))
				total++;
		}
	}

	printf("%d\n", total);

	return 0;
}