#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int ready[8];
int maxval = 0;
bool visit[8];
int calculate(int n) {
	int temp = 0;
	
	for (int i = 0; i < n-1; ++i) {
		temp+=abs(ready[i] - ready[i + 1]);
	}

	return temp;
}

void get(int depth, int n, const vector<int> &arr) {


	if (depth == n) {
		int temp = 0;
		temp = calculate(n);
		maxval = max(temp, maxval);
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (!visit[i]) {
			ready[depth] = arr[i];
			visit[i] = true;
			get(depth + 1, n, arr);
			visit[i] = false;
		}
	}



}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> ar(n);

	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
	}

	get(0, n, ar);

	cout << maxval;
}