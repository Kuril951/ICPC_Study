#include<iostream>
#include<memory.h>

using namespace std;

int Team[101][102];
int team_info[101][2];		//0 제출 횟수 1 제출시간

int main()
{
	int T, n, k, t, m;

	scanf("%d", &T);

	while (T--)
	{
		int team, pro_num, score, cnt = 0;

		memset(Team, 0, sizeof(Team));
		memset(team_info, 0, sizeof(team_info));

		scanf("%d %d %d %d", &n, &k, &t, &m);

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &team, &pro_num, &score);

			if (Team[team][pro_num] < score)
				Team[team][pro_num] = score;
			team_info[team][0]++;
			team_info[team][1] = i;
		}

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				Team[i][101] += Team[i][j];

		for (int i = 1; i <= n; i++)
		{
			int my_score = Team[t][101];

			if (Team[i][101] >= my_score && i != t)
			{
				if (Team[i][101] == my_score)
				{
					if (team_info[i][0] < team_info[t][0])
						cnt++;
					else if (team_info[i][0] == team_info[t][0])
						if (team_info[i][1] < team_info[t][1])
							cnt++;
				}
				else
					cnt++;
			}
		}

		printf("%d\n", cnt + 1);
	}


	return 0;
}
