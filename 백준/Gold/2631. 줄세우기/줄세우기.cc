#include<iostream>
#include<vector>
using namespace std;

int dp[201];

int main() {

	int n, maximum=0;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		maximum = max(dp[i], maximum);
	}

	cout << n - maximum << endl;
}