#include<iostream>
#include<vector>
#include<cstring>
using namespace std;


int main() {
		
	int n, m, k, c;
	cin >> n >> m >> k >> c;
	int max = 0;
	vector<int> arr(n,0);
	bool li[30001] = { false, };
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; ++i) {
		int ks = 0;
		for (int j = i; j < i + k; ++j) {

			if (!li[arr[j % n]]) {
				li[arr[j % n]] = true;
				ks++;
			}
			
		}
		if (li[c] == 0) ks += 1;
		max = ks > max ? ks : max;
		memset(li, false, sizeof(li));
	}
	
	printf("%d", max);
}