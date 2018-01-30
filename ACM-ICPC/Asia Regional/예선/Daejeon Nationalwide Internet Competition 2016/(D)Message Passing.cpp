#include <iostream>
#include <stdio.h>

#define MOD 31991

using namespace std;

int b_m[50][50];
int m[50][50];
int t_m[50][50];
int d, t;

int main()
{
	cin >> d >> t;

	for(int i=0; i< (d - 1); i++)
		b_m[i][0] = b_m[i][i+1] = m[i][0] = m[i][i+1] = 1;
	b_m[d - 1][0] = m[d - 1][0] = 1;

	for(;t; t>>=1){
		if(t & 1) {
			for(int y=0; y<d; y++){
				for(int x=0; x<d; x++){
					t_m[y][x] = 0;
					for(int i=0; i<d; i++)
						t_m[y][x] = (t_m[y][x] + (m[y][i] * b_m[i][x]) % MOD) % MOD;
				}
			}
			for(int i=0; i<d; i++)
				for(int j=0; j<d; j++)
					b_m[i][j] = t_m[i][j];
		}

		for(int y=0; y<d; y++){
			for(int x=0; x<d; x++){
				t_m[y][x] = 0;
				for(int i=0; i<d; i++)
					t_m[y][x] = (t_m[y][x] + (m[y][i] * m[i][x]) % MOD) % MOD;
			}
		}
		//copy
		for(int i=0; i<d; i++)
			for(int j=0; j<d; j++)
				m[i][j] = t_m[i][j];
	}

	printf("%d\n", b_m[0][1]);


	return 0;
}
