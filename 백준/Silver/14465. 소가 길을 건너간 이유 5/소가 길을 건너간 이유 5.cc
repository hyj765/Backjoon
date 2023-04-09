#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	int bd = 0;
	int minvalue = INT32_MAX;
	cin >> n >> m >> k;
	vector<bool> bpfl(n+1,0);
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		bpfl[x] = true;
		if (x <= m) {
			bd++;
		}
	}
	minvalue = bd;
	for (int i = m+1; i <= n; ++i) {
		if (bpfl[i]) bd++;
		if (bpfl[i - m]) bd--;
		
		minvalue = min(bd, minvalue);
	}
	printf("%d", minvalue);
}