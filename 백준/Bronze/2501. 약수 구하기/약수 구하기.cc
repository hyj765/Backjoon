#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> arr;

	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			arr.push_back(i);
		}
	}
	if (arr.size() < m) cout << 0 << endl;
	else cout << arr[m - 1];
}