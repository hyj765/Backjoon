#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;


	long long dp[91];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	/*
	
		1000
		1001
		1010

		10010
		10100

		101001
		

		1000000
		1000001
		1010101
		1000001

		1001010
		1010001
		1001001
		1000101

	*/



}