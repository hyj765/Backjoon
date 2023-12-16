#include<iostream>
#include<vector>
using namespace std;


int dp[500][500];

int main() {

	int n,answer = 0;

	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> arr[i][j];
		}
	}
	
	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	
	for (int i = 0; i < n; ++i) answer = max(answer, dp[n - 1][i]);
	
	cout << answer;
}