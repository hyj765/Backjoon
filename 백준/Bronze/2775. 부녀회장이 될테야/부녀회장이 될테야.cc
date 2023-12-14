#include<iostream>
#include<vector>

using namespace std;



/*

	dp[a][b] = dp[a-1][b]
	
	[1][3] = 6;
		
	[0][i] = 1 2 3 .....
	[1][1] = 1;
	[1][2] = 3;
	[1][3] = 6;

	dp[k][n] = dp[i - 1][n] + dp[i][n-1];

	dp[k][n] = dp[i-1][n-1] .....

*/

int dp[15][15];

int main() {
	
	int T,k, n;
	cin >> T;
	for (int i = 1; i <= 14; ++i) {
		dp[0][i] = i;
	}

	for (int i = 1; i <= 14; ++i) {
		for (int j = 1; j <= 14; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	for (int i = 0; i < T; ++i) {
		cin >> k;
		cin >> n;

		cout << dp[k][n] << endl;
	}

}