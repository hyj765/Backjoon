#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int cnt = 0;





int main() {

	int k, n, m;

	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> n >> m;
		int res = 1, temp = 1;
		for (int j = m; j > m - n; --j) {
			res = res * j;
			res = res / temp++;
		}

		cout << res << endl;
	}

}