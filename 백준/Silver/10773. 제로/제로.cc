#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int answer = 0;
	int n;
	stack<int> value;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		if (v == 0)
		{
			if (value.empty() == false)
			{
				value.pop();
			}

			continue;
		}
		value.push(v);
	}
	
	while (value.empty() == false)
	{
		answer +=value.top();
		value.pop();
	}

	cout << answer;

}