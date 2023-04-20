#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

	int n,c;
	cin >> n >> c;
	vector<int> arr(n,0);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	int start = 0;
	int end = arr[n - 1] - arr[0];
	int maxvalue = 0;

	while (start <= end) {
		int router = 1;
		int mid = (start + end) / 2;
		int first = arr[0];

		for (int i = 1; i < n; ++i) {
			int second = arr[i];
			if (second - first >= mid) {
				router += 1;
				first = second;
			}
		}

		if (router >= c) {
			maxvalue = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
}

	printf("%d", maxvalue);
}