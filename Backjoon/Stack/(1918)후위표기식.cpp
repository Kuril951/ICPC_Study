#include<iostream>
#include<stack>
#include<cstring>
#include<vector>

using namespace std;

// operatorPriority
int op(char c)
{
	if (c == '(' || c == ')')
		return 0;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
}

int main()
{
	stack<char> st;
	char str[101];

	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if ('A' <= c && c <= 'Z')
			printf("%c", c);
		else {
			if (c == '(')
				st.push(c);
			else if (c == ')') {
				while (st.top() != '(') {
					printf("%c", st.top());
					st.pop();
				}
				st.pop();
			}
			else {
				while (!st.empty() && op(st.top()) >= op(c)) {
					printf("%c", st.top());
					st.pop();
				}
				st.push(c);
			}
		}
	}
	while (!st.empty()) {
		printf("%c", st.top());
		st.pop();
	}
	
	return 0;
}