#include<iostream>
#include<vector>

using namespace std;

/*

	dp[3] = [2][1] + [1][2]
	dp[4] = 5
	dp[5] = 8
	dp[6] = 13
	dp[7] = 21
	dp[8] = 34
	dp[9] = 55
	111

	- 
	- 1 
	
	1 -
	  -

	  ----   1111
	  ----

	  11-- --11  1 -- 1
		-- --	   --		--11--

*/

int dp[1001];

int main() {
	
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	}

	cout << dp[n]<< endl;

}