#include<iostream>
#include<cstring>

using namespace std;

int rooms[300001];

int find(int n)
{
	if (rooms[n] < 0)
		return n;
	return rooms[n] = find(rooms[n]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) {
		if (rooms[a] == -1) {
			rooms[a] = -2;
			return true;
		}
		else
			return false;
	}
	else
	{
		if (rooms[a] == -2 && rooms[b] == -2) {
			rooms[a] = b;
			return false;
		}
		else if (rooms[a] == -2)
			rooms[b] = a;
		else
			rooms[a] = b;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(rooms, -1, sizeof(rooms));

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (merge(a, b))
			cout << "LADICA\n";
		else
			cout << "SMECE\n";
	}

	return 0;
}