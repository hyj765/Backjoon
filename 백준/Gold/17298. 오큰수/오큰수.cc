#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int dp[1000001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int n;
	cin >> n;

	stack<int> st;
	vector<int> vl(n);
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		vl[i] = data;

		while (1) {
			if (st.empty() == true)
			{
				st.push(i);
				break;
			}

			int idx = st.top();
			if (data > vl[idx])
			{
				dp[idx] = data;
				st.pop();
			}
			else {
				st.push(i);
				break;
			}
		}
	}

	while (st.empty() == false)
	{
		int idx = st.top();
		st.pop();
		dp[idx] = -1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << dp[i] << " ";
	}
}