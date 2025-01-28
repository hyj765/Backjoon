#include<iostream>
#include<vector>
#include<stack>
using namespace std;

string remove_bomb(char trigger,const string& str, const string& bombcmd)
{
	string chstr = "";
	for (int i = 0; i < str.size(); ++i)
	{
		chstr.push_back(str[i]);
		if (chstr.back() == trigger && chstr.size() >= bombcmd.size())
		{
			if (chstr.substr(chstr.size() - bombcmd.size(), bombcmd.size()) == bombcmd)
			{
				chstr.erase(chstr.end() - bombcmd.size(), chstr.end());
			}
		}
	}

	return chstr;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a1, a2;
	cin >> a1 >> a2;

	auto answer =remove_bomb(a2[a2.size() - 1], a1, a2);
	if (answer.empty())
	{
		printf("FRULA\n");
	}
	else {
		printf("%s",answer.c_str());
	}
}