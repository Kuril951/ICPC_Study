/*
 * Google Code Jam
 * 2018-04-07
 * (D) Cubic UFO (visible)
 * Made by Kuril951
 */

#include<iostream>
#include<cmath>

# define M_PI 3.14159265358979323846

using namespace std;

void rotationMatrix(double pos[3], double angle)
{
	double x = pos[0], y = pos[1], z = pos[2];
	double c = cos(angle), s = sin(angle);
	
	pos[0] = c * x - s * y;
	pos[1] = s * x + c * y;
}

double roundDouble(double n, int idx)
{
	int p = pow(10, idx);
	return floor(n * p + 0.5) / p;
}

int main()
{
	int T;

	scanf("%d", &T);

	for(int t = 1; t<=T; t++)
	{
		double A;

		scanf("%lf", &A);
		double rAngle = roundDouble(M_PI / 4 - acos(roundDouble(A / sqrt(2.0), 6)), 6);
		double pos[3][3] = { {0.5,0,0},{0,0.5,0},{0,0,0.5} };

		printf("Case #%d:\n", t);
		for (int i = 0; i < 3; i++) {
			rotationMatrix(pos[i], rAngle);
			printf("%lf %lf %lf\n", pos[i][0], pos[i][1], pos[i][2]);
		}	
	}


	return 0;
}