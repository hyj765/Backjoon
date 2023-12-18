#include<iostream>
#include<vector>
#include<set>
using namespace std;

int dp[1001];
set<int> dparr[1001];
int main() {

	int n, temp=0, locate=0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[i] > arr[j] && dp[i] < dp[j]+1) {
				dp[i] = dp[j] + 1;
				dparr[i] = dparr[j];
				dparr[i].insert(arr[j]);
			}
		}
		dparr[i].insert(arr[i]);

		if (temp < dparr[i].size()) {
			temp = dparr[i].size();
			locate = i;
		}

	}

	cout << dparr[locate].size() << '\n';
	for (int s : dparr[locate]) cout << s << " ";

}