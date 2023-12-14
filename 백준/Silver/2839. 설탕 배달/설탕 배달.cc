#include<iostream>
#include<vector>
using namespace std;

int dp[5001];
int main() {
	
	int n;

	cin >> n;

	dp[3] = dp[5] = 1;
	/*
		dp[3] = 1;
		dp[6] = 2;
		dp[9] = 3
		dp[10] = 2;
		dp[11] = 3;
		dp[i - 5] = 2 + 1 == 3

	*/
	for (int i = 6; i <= n; ++i) {
		if (dp[i - 3]) dp[i] = dp[i - 3] + 1;

		if (dp[i - 5]) dp[i] = dp[i - 5] + 1;
	}

	if (dp[n]) {
		cout << dp[n];
	}
	else {
		cout << -1;
	}
}