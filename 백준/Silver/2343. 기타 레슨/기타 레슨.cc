#include<iostream>
#include<vector>

using namespace std;

#define ll long long

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> arr(n, 0);
	ll maxv = 0;
    int low = 0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		maxv += arr[i];
        low = max(arr[i],low);
	}
	while (low <= maxv) {
		ll cur = 0;
		ll cnt = 0;
		ll middle = (low + maxv) / 2;
		for (int i = 0; i < n; ++i) {
			if (cur + arr[i] > middle) {
				cur = 0;
				cnt++;
			}
			cur += arr[i];
		}
		if (cur != 0) cnt++;

		if (cnt <= m) {
			maxv = middle - 1;
		}
		else {
			low = middle + 1;
		}

		

	}
	
	cout << low;


}