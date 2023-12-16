#include<iostream>
#include<vector>
using namespace std;


int dp[301];


int main() {

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	dp[0] = 0;
	dp[1] = arr[0];
	dp[2] = arr[0] + arr[1];
	dp[3] = max(arr[1] + arr[2], arr[0] + arr[2]);
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i-3]+arr[i-1] + arr[i-2],arr[i-1] + dp[i-2]);
	}

	cout << dp[n];
}