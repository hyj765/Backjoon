#include<iostream>
#include<vector>

using namespace std;

int dp[1000001];

int main() {

	int x;
	cin >> x;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= x; ++i) dp[i] = INT32_MAX;
	
	// dp[5] = dp[4] + 1;
	// dp[6] = dp[6/2] +1 , dp[6/3] +1, dp[6-1] +1;
	// dp[7] = dp[7-1] +1;
	// dp[8] = dp[i/2] + 1 , dp[i-1] +1;
	// dp[15] = dp[15/3] +1 , dp[i-1] +1;

	for (int i = 4; i <= x; ++i) {
		if (i % 3 == 0) {
			dp[i] = dp[i / 3] + 1;
		}
		
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}

		dp[i] = min(dp[i], dp[i - 1] + 1);

	}

	cout << dp[x];

}