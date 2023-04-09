#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long long cnt = 0;
	long long maxValue = 0;
	if (m == 0) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		cnt += arr[i];
	}
	maxValue = cnt;
	for (int i = m; i < n; ++i) {
		cnt += arr[i];
		cnt -= arr[i - m];
		maxValue = max(cnt, maxValue);
	}

	cout << maxValue;
}