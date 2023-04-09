#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	vector<int> lionarr;
	lionarr.reserve(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if(arr[i] == 1) lionarr.push_back(i);
	}
	int cnt = INT32_MAX;
	if (lionarr.size() >= m) {
		for (int i = 0; i <= lionarr.size() - m; ++i) {
			cnt = min(cnt, lionarr[i + m - 1] - lionarr[i] + 1);
		}
	}
	if (cnt == INT32_MAX) printf("-1");
	else printf("%d", cnt);
}