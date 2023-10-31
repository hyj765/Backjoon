#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[1001];
	int dp[1001];
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i) {
		dp[i] = 1;
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {

			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}
	}

	sort(dp, dp + n + 1);
	cout << dp[n];

}