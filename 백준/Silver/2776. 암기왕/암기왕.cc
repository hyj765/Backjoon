#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

bool binsearch(const vector<int>& arr, int value) {
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end) {
		int middle = (start + end) / 2;
		
		if (arr[middle] == value) return true;
		if (arr[middle] > value) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}

	}

	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		
		cin >> m;
		vector<int> arr(m);
		map<int, bool> pre;
		for (int j = 0; j < m; ++j) {
			cin >> arr[j];
		}
		sort(arr.begin(), arr.end());
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int s; 
			cin >> s;
			if (pre[s]) {
				printf("1\n");
				continue;
			}
			if (binsearch(arr,s)) {
				pre[s] = true;
				printf("1\n");
			}
			else {
				printf("0\n");
			}
			
		}

	}

}