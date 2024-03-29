#include<iostream>
#include<vector>

using namespace std;

int dp[11];

int main() {
	int T,n;
	cin >>  T;
	dp[0] = 0;
	dp[1] = 1; //	1
	dp[2] = 2; //  11 2										     1 = 1  2 = 1 
	dp[3] = 4; // 111, 21 , 12, 3  //							 1 = 2  2 = 1 3 = 1
	dp[4] = 7; //1111, 121, 211, 31 , 112, 22, 13                1 = 4 , 2 = 2  3= 1 
	// 5 = 11 + 2 == 13
	// 6 = 13 + 7 + 4 == 24 
	// 7 = 24 + 13 + 7
			   
	// 5 =       11111, 1112, 1121, 1211, 21111, 131, 311, 221, 122, 212, 32, 23, 113    1 = 8 , 2=3   3= 2

	for (int i = 5; i <= 10; ++i) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}
	for (int i = 0; i < T; ++i) {
		cin >> n;
		cout << dp[n] << endl;
	}
}