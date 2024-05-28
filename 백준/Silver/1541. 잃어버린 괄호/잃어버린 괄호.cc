#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



int main()
{
	int answer = 0;
	bool isminus = false;

	string vs;
	cin >> vs;
	
	string num = "";
	for (int i = 0; i <= vs.size(); ++i)
	{
		if (vs[i] == '-' || vs[i] == '+' || i == vs.size())
		{
			if (isminus)
			{
				answer -= stoi(num);
				num = "";
			}
			else {
				answer += stoi(num);
				num = "";
			}
		}
		else 
		{
			num += vs[i];
		}

		if (vs[i] == '-') isminus = true;
	}

	cout << answer;
}