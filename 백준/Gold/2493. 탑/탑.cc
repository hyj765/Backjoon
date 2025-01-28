#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int dp[500001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	cin >> n;
	// 6 9 6 5 5 7 4
	stack<pair<int,int>> st;
	vector<int> vl(n);

	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;

			while (st.empty() == false)
			{
				if (st.top().second > data)
				{
					int indx = st.top().first;
					dp[i] = indx+1;
					st.push({ i,data });
					break;
				}

				st.pop();
			}
			if (st.empty())
			{
				dp[i] = 0;
			}
			st.push({ i,data });

	}

	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << " ";
	}

}