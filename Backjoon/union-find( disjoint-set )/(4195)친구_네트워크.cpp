#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;

map<string, int> name;
int network[100001];

int find(int n)
{
	if (network[n] < 0)
		return n;
	return network[n] = find(network[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	network[a] += network[b];
	network[b] = a;	// b's parent node is a
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;
	while (t--)
	{
		memset(network, -1, sizeof(network));
		int F;
		cin >> F;

		name.clear();

		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			name.insert({ a, name.size() });
			name.insert({ b, name.size() });
			merge(name[a], name[b]);
			cout << -network[find(name[a])] << "\n";
		}
	}

	return 0;
}