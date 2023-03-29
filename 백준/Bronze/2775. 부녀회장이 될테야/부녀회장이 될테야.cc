#include<iostream>

//a:b = f( a-1 + ... )

using namespace std;
// 1층 3호
// 1 2 3 arr 0
// 1 3 6 arr 1
int main() {
	//T 
	// k n
	// k n
	int T, k, n;
	cin >> T;
	int dp[15][15] = {0,};

	dp[0][0] = 0;
	for (int i = 1; i < 15; ++i) {
		dp[0][i] = i;
	}

	for (int i = 1; i < 15; ++i) {
		for (int j = 1; j < 15; ++j) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j]; 
		}
	}
	for (int i = 0; i < T; ++i) {
		cin >> k >> n;
		printf("%d\n", dp[k][n]);
	}
}