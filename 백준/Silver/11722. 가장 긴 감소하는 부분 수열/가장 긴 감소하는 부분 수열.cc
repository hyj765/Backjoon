#include<iostream>
#include<vector>
using namespace std;

int dp[1001];
int main() {

	int n,answer = 0;
	cin >> n;
	
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] > arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		answer = max(answer, dp[i]);
	}

	cout << answer;
}