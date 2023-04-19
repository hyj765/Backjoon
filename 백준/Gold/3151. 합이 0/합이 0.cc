#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

	int n;
	cin >> n;

	long long cnt = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			int v = arr[i] + arr[j];

			int start = lower_bound(arr.begin() + j + 1, arr.end(),  ( - v))-arr.begin();
			int end =upper_bound(arr.begin() + j + 1, arr.end(), (-v)) - arr.begin();
			cnt += end- start;
		}
	}

	
	cout << cnt;


}