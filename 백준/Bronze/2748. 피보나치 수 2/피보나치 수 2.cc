#include <string>
#include <vector>
#include<iostream>
#define ll long long
using namespace std;



ll dp[91];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	
	for (int i = 3; i <= 90; ++i) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];

}