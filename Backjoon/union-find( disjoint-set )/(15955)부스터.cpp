/*
*	x, y축 정렬, query정렬 후
*	hp가 작은순으로
*	노드를 묶으면서(union-find) 탐색
*/

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<functional>
#include<cstring>

#define MAX_V 250001
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
int answer[MAX_V];

using namespace std;

struct cmp {
	bool operator()(piii a, piii b) {
		return a.first > b.first;
	}
};

class Query {
public:
	int a, b, hp, idx;

	Query(int idx, int a, int b, int hp)
	{
		this->idx = idx;
		this->a = a;
		this->b = b;
		this->hp = hp;
	}

	bool operator<(const Query &a) const {
		return this->hp < a.hp;
	}
};

int N, Q;
int tree[MAX_V];
vector<pii> xv, yv;
priority_queue<piii, vector<piii>, cmp> pq;
vector<Query> query;

// union-find algorithm
int find(int i)
{
	if (tree[i] == -1)
		return i;
	return tree[i] = find(tree[i]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		tree[b] = a;
}

int main()
{
	memset(tree, -1, sizeof(tree));
	scanf("%d %d", &N, &Q);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		xv.push_back({ a, i + 1 });
		yv.push_back({ b, i + 1 });
	}

	// nlogn
	sort(xv.begin(), xv.end());
	sort(yv.begin(), yv.end());

	for (int i = 0; i < N - 1; i++) {
		pq.push({ xv[i + 1].first - xv[i].first,  {xv[i].second, xv[i + 1].second} });
		pq.push({ yv[i + 1].first - yv[i].first,  {yv[i].second, yv[i + 1].second} });
	}
	
	for (int i = 0; i < Q; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);;
		query.push_back(Query(i, a, b, c));
	}

	// nlogn
	sort(query.begin(), query.end());

	// nlogn
	for (int i = 0; i < Q; i++) {
		Query q = query[i];
		int hp = q.hp;

		while (!pq.empty() && pq.top().first <= hp) {
			piii edge = pq.top();
			pq.pop();
			merge(edge.second.first, edge.second.second);
		}

		if (find(q.a) == find(q.b))
			answer[q.idx] = 1;
		else
			answer[q.idx] = 0;
	}

	for (int i = 0; i < Q; i++) {
		if (answer[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}