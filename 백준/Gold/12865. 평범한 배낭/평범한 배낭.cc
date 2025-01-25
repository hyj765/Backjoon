#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int k[100001];
int w[100001];

int dp[101][100001];

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> k[i] >> w[i];
	}

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= m; ++j)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				continue;
			}
			int weight = k[i - 1];
			int value = w[i - 1];

			if (j >= weight)
			{
				dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][m];
}