#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int cnt = 0;
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = n - 1;
	while (left < right) {
		int sum=arr[left] + arr[right];
		if (sum == m) {
			cnt++;
			left++;
		}
		else if (sum > m) {
			right--;
		}
		else {
			left++;
		}
	}

	printf("%d", cnt);
}