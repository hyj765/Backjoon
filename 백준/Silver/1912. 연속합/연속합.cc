#include<iostream>
#include<vector>
using namespace std;


int dp[100001];

int main() {

	int n,answer = -2000;
	cin >> n;
	vector<int> arr(n);


	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	dp[0] = -2000;
	dp[1] = arr[0];

	for (int i = 2; i <= n; ++i) {
		dp[i] = max(arr[i - 1], dp[i-1]+arr[i-1]);
	}


	for (int i = 1; i <= n; ++i) {
		answer = max(answer, dp[i]);
	}
	
	cout << answer;
}