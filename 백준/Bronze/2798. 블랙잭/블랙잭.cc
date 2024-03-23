#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	int answer = INT32_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < n-2; ++i) {
		for (int j = i+1; j < n-1; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int temp = arr[i] + arr[j] + arr[k];
				if (abs((temp - m)) < abs(answer - m) && temp <= m) {
					answer = temp;
				}
			}
		}
	}

	cout << answer;

}