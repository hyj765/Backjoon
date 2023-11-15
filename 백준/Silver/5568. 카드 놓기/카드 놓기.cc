#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;

bool visit[10];
set<string> table;
void solv(int depth,int k, const vector<int>& arr, string s) {

	if (depth == k) {
		table.insert(s);
		return;
	}


	for (int i = 0; i < arr.size(); ++i) {
		if (!visit[i]) {
			visit[i] = true;
			string temp = s + to_string(arr[i]);
			solv(depth + 1, k, arr, temp);
			visit[i] = false;
		}
	}
	



}


int main() {

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	string s = "";
	solv(0,k, arr,s);

	cout << table.size();

}