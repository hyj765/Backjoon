#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int dp[2][100001];

int main() {
	/*
	
		50 10 100 20 40
		30 50 70 10 60
		
	*/

	int m,n;
	cin >> m;

	for (int k = 0; k < m; ++k) {
		cin >> n;
		vector<vector<int>> stickers(2, vector<int>(n + 1, 0));

		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> stickers[i][j];
			}
		}
		dp[0][1] = stickers[0][1];
		dp[1][1] = stickers[1][1];

		for (int i = 2; i <= n; ++i) {
			dp[0][i] = stickers[0][i] + max(dp[1][i - 1], max(dp[1][i - 2], dp[0][i - 2]));
			dp[1][i] = stickers[1][i] + max(dp[0][i - 1], max(dp[0][i - 2], dp[1][i - 2]));
		}

		cout << max(dp[0][n], dp[1][n]) << endl;
		
	}

	

}