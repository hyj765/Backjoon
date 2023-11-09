#include<iostream>
#include<vector>
using namespace std;

int dp[500][500];

/*

		7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5



	i == 0
	dp[i][j] = dp[i-1][j] + arr[i][j];
	else if(i == j)
	dp[i][j] = dp[i-1][j-1] + arr[i][j];
	else
	dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j]; 
	
*/


int main(){

	int n, answer=0;
	cin >> n;

	

	vector<vector<int>> arr(n);
	
	

	int num; 
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> num;
			arr[i].push_back(num);
		}
	}
	dp[0][0] = arr[0][0];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0) dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (i == j) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		answer = max(dp[n - 1][i],answer);
	}
	cout << answer;
}