#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
queue<int> truck;
queue<int> bridge;

int main()
{

	scanf("%d %d %d",&n,&w,&L);

	for(int i=0; i<n; i++){
		int tmp;
		scanf("%d", &tmp);
		truck.push(tmp);
	}

	for(int i=0; i<w; i++)
		bridge.push(0);
	int cL = 0;
	int time = 0;
	while(!truck.empty())
	{
		cL -= bridge.front();
		bridge.pop();
		if(cL + truck.front() <= L)
		{
			cL += truck.front();
			bridge.push(truck.front());
			truck.pop();
		}
		else
			bridge.push(0);
		time++;
	}

	printf("%d", time + w);


	return 0;
}
