#include <iostream>
#include<vector>
using namespace std;
// 6 6
// 1 1 1 1 1 1  6이다
int main() {

	int n, m, cnt =0;
	cin >> n >> m;
	vector<int> arr(n,0);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long long mv = 0;
	long long cur = 0;
	for (int i = 0; i < m; ++i) {
		cur += arr[i];
	}
	mv = cur;
	for (int i = m; i < n; ++i) {
		cur += arr[i];
		cur -= arr[i - m];
		mv = max(cur, mv);
	}

	if (mv != 0) {
		cur = 0;
		for (int i = 0; i < n; ++i) {
			cur += arr[i];
			if ( (i - m) >= 0) {
				cur -= arr[i - m];
			}
			if (i - (m -1) >= 0 &&cur == mv) {
				cnt++;
			}
		}
	}
	
	if (n == m) cnt = 1;



	if (mv == 0) printf("SAD");
	else {
		printf("%ld", mv);
		printf("\n%d", cnt);
	}
}