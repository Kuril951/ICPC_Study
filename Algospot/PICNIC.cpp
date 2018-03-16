#include<iostream>
#include<memory.h>

using namespace std;

int student[10][10];
int havePartner[10];
int n, m;		//n: 학생수, m : 친구 쌍의 수
int cnt;

void func(int st_idx)
{
	if (st_idx == n - 1) {
		cnt++;
		return;
	}
	if (havePartner[st_idx]) {
		func(st_idx + 1);
		return;
	}

	for (int i = st_idx; i < n; i++) {
		if (student[st_idx][i] && !havePartner[i]) {
			havePartner[i] = havePartner[st_idx] = 1;
			student[i][st_idx] = 0;
			func(st_idx + 1);
			havePartner[i] = havePartner[st_idx] = 0;
			student[i][st_idx] = 1;
		}
	}
}

int main()
{
	int T;			//테스트 케이스 수

	scanf("%d", &T);
	
	while(T--)
	{
		memset(student, 0, sizeof(student));
		memset(havePartner, 0, sizeof(havePartner));
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int f1, f2;
			scanf("%d %d", &f1, &f2);
			student[f1][f2] = student[f2][f1] = 1;
		}
		func(0);
		printf("%d\n", cnt);
	}
	
	return 0;
}