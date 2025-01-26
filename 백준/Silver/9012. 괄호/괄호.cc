#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool isAnswer(const string& str)
{
	stack<char> st;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == '(')
		{
			st.push(str[i]);
		}
		else {
			if (st.empty())
			{
				return false;
			}
			else {
				st.pop();
			}
		}
	}

	if (st.empty() == false) return false;

	return true;
}

int main()
{
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (isAnswer(str))
		{
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	
	}


}