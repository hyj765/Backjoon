#include<iostream>
#include<vector>
using namespace std;

int maxprofit = 0;
void getsimualte(int depth, const vector<pair<int,int>> arr,int value,int n) {

	if (depth >= n) {
		maxprofit = max(value, maxprofit);
		return;
	}
	if (depth + arr[depth].first <= n) {
		getsimualte(depth + arr[depth].first, arr, value + arr[depth].second, n);
	}
	getsimualte(depth + 1, arr, value, n);
}




int main() {

	int n;
	cin >> n;

	vector<pair<int,int>> arr(n);

	for (int i = 0; i < n; ++i) {
		int day, cost;
		cin >> day >> cost;
		arr[i].first = day;
		arr[i].second = cost;
	}

	getsimualte(0, arr, 0, n);
	cout << maxprofit;
}