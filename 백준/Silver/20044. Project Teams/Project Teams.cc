#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
	int n, min = 999999;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> max_qt;
	priority_queue<int> min_qt;
	for (int i = 0; i < 2 * n; i++) {
		int v;
		cin >> v;
		max_qt.push(v);
		min_qt.push(v);
	}
	int cnt = n;
	while (cnt != 0) {
		if (min_qt.top() + max_qt.top() < min) min = min_qt.top() + max_qt.top();
		min_qt.pop();
		max_qt.pop();
		cnt--;
	}
	cout << min;
}