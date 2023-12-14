#include<iostream>
#include<vector>

using namespace std;

int dp[41][2];

int main() {
	
	int T,n;
	cin >> T;
	dp[0][0] = 1;
	dp[0][1] = 0;

	dp[1][1] = 1;
	dp[1][0] = 0;

	dp[2][1] = 1;
	dp[2][0] = 1;

	dp[3][1] = 2;
	dp[3][0] = 1;

	for (int i = 4; i <= 40; ++i) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	for (int i = 0; i < T; ++i) {
		cin >> n;

		cout << dp[n][0] << " " << dp[n][1] << endl;
	}


}