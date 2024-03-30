#include <string>
#include <vector>
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long dp[1001];
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n]; 
}