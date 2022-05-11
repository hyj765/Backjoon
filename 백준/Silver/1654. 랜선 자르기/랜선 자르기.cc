#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> ar(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	long long result = 0;
	long long start = 1;
	long long end = *max_element(ar.begin(),ar.end());
	sort(ar.begin(), ar.end());

	while (start <= end) {
		long long ransun = 0;
		long long mid = (start + end) / 2;
		for (auto x : ar) {
			if ((x / mid) > 0) {
				ransun += x / mid;
			}
		}
		if (ransun >= m) {
			start = mid + 1;
			result = max(result,mid);

		}else {
			end = mid - 1;
		}

	}

	cout << result;
}