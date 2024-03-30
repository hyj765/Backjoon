#include <string>
#include <vector>
#include<iostream>
using namespace std;

/*

	1. 포도주 잔을 선택 시에 그 잔에 들어있는 포도주는 모두 마셔야한다. 마신 후 원래 위치에 다시 놓아야한다.?
	2. 연속 3잔 마시기 불가.

	(n + n+1 + n+3) , n + n+2 + n+3)
*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long dp[10001];
	dp[0] = 0;
	vector<long long> s(n+1);

	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}

	dp[1] = s[1];
	dp[2] = s[2] + s[1];
	for (int i = 3; i <= n; ++i) {
		dp[i] = max(max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]),dp[i-1]);
	}

	/*	
	
	*/


	cout << dp[n];
	
}