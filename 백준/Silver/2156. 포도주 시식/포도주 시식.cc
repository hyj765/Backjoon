#include<iostream>
#include<vector>
using namespace std;



int dp[10001];

int main() {

	int n;
	cin >> n;

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	dp[0] = arr[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; ++i) {
		int temp = dp[i - 3] + arr[i - 1] + arr[i];
		int temp2 = dp[i - 2] + arr[i];
		int temp3 = dp[i - 1];
		dp[i] = max(temp3,max(temp2,temp));
	}


	cout << dp[n];
	/*
		1 3 , 1 2, 2 3

		dp[3] = max(dp[i-3] + arr[i-2] + arr[i-1], dp[i-2] + arr[i], 	
		0 6 10 13 9 8 1

	
	
	*/

}