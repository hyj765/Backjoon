#include<iostream>
#include<vector>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	int answer = 0;
	int maxanswer;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; ++i) {
		answer += arr[i];
	}
	maxanswer = answer;
	for (int i = m; i < n; ++i) {
		answer += arr[i];
		answer -= arr[i - m];
		maxanswer = max(maxanswer, answer);
	}
	cout << maxanswer;
}