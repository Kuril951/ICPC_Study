#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

double getOperand(stack<double> &st)
{
	double a = st.top();
	st.pop();
	return a;
}

double getScore(double v1, double v2, char c)
{
	switch (c)
	{
	case '+':
		return v1 + v2;
	case '-':
		return v1 - v2;
	case '*':
		return v1 * v2;
	case '/':
		return v1 / v2;
	}
}

int main()
{
	int cnt;
	stack<double> st;
	char str[101];
	int score[50];

	scanf("%d", &cnt);
	scanf("%s", str);
	for (int i = 0; i < cnt; i++)
		scanf("%d", &score[i]);

	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];

		if ('A' <= c && c <= 'Z')
			st.push(score[c - 'A']);
		else {
			double v2 = getOperand(st);
			double v1 = getOperand(st);
			st.push(getScore(v1, v2, c));
		}
	}

	printf("%.2lf", st.top());

	return 0;
}