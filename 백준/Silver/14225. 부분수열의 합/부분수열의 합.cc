#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

map<long long,bool> s;
void dfs(const vector<int>& arr, int depth,long long x) {
	s[x] = true;
	if (depth == arr.size()) return;
	dfs(arr,depth + 1,x+arr[depth]);
	dfs(arr, depth + 1, x);
}


int main(int argc, char* argv[]) {

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		s[arr[i]] = true;
	}
	dfs(arr, 0, 0);
	for (int i = 0; i < 2000001; ++i) {
		if (!s[i]) {
			cout << i;
			break;
		}
	}

}