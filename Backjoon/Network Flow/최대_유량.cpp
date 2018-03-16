#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

const int MAX_V = 200;

inline int CtoI(char c) {
	if (c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

int main() {
	int N; // ���� ����
	int c[MAX_V][MAX_V] = { 0 }; // c[i][j]: i���� j�� ���� ������ �뷮
	int f[MAX_V][MAX_V] = { 0 }; // f[i][j]: i���� j�� ���� �帣�� ����
	vector<int> adj[MAX_V]; // ���� ����Ʈ

							// ���� ���� �Է¹ޱ�
	scanf("%d", &N);
	for (int i = 0; i<N; i++) {
		char u, v;
		int w;
		scanf(" %c %c %d", &u, &v, &w);
		u = CtoI(u); v = CtoI(v);
		c[u][v] += w; // ���� ������ ���� �� ���� �� �����Ƿ� +=
		adj[u].push_back(v);
		adj[v].push_back(u); // ������ ������ �߰������ ��
	}

	// total: �� ����, S: �ҽ�, E: ��ũ
	int total = 0, S = CtoI('A'), E = CtoI('Z');
	// ���� ��θ� �� ã�� ������ ����
	while (1) {
		// ���� ��θ� BFS�� ã��
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> Q;
		Q.push(S);
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			for (int next : adj[curr]) {
				// c[i][j]-f[i][j] > 0: i���� j�� ������ �긱 ������ ���Ҵ°�?
				// prev[next] == -1: next ������ ���� �湮���� �ʾҴ°�?
				if (c[curr][next] - f[curr][next] > 0 && prev[next] == -1) {
					Q.push(next);
					prev[next] = curr; // ��θ� ����ϱ� ���� prev �迭 ���
					if (next == E) break; // ��ũ�� �����ϸ� ����
				}
			}
		}
		// ��ũ�� ���� ��ΰ� �� ������ ���� Ż��
		if (prev[E] == -1) break;

		// ��λ󿡼� ���� ���ġ�� ���� ���� ã��
		int flow = INT_MAX;
		for (int i = E; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		// ã�� flow��ŭ �ش� ��ο� ���� �����
		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		// �� ���� �� ����
		total += flow;
	}
	// ��� ���
	printf("%d\n", total);
}
