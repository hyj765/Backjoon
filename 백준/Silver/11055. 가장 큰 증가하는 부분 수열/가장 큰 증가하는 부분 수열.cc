#include<iostream>
#include<vector>
using namespace std;

int dp[1001];

int main() {

	int n,answer = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	dp[0] = arr[0];
	for (int i = 0; i <n; ++i) {
		dp[i] = arr[i];
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i],dp[j]+arr[i]);
			}
		}

		answer = max(answer, dp[i]);
	}

	cout << answer;

}