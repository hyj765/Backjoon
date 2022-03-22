#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> max_h;
	priority_queue<int,vector<int>,greater<int>> min_h;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (max_h.size() == min_h.size()) max_h.push(num);
		else min_h.push(num);
		if (!max_h.empty() && !min_h.empty()) {
			if (max_h.top() > min_h.top()) {
				int a = max_h.top();
				int b = min_h.top();
				max_h.pop();
				min_h.pop();
				max_h.push(b);
				min_h.push(a);
			}
		}
		cout << max_h.top() << '\n';
	}
}