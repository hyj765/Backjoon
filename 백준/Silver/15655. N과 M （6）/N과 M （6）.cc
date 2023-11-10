#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visit[8];
int temp[8];


void solv(int n,int m,int depth, const vector<int>& arr,int start) {
	if (depth == m) {
		for (int i = 0; i < m; ++i) {
			cout << temp[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; ++i) {
		if (!visit[i]) {
			visit[i] = true;
			temp[depth] = arr[i];
			solv(n, m, depth + 1, arr, i);
			visit[i] = false;
		}
	}


}



int main() {

	int n, m;

	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());

	solv(n, m, 0,arr,0);


}