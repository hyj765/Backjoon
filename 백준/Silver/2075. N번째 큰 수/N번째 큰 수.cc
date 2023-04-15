#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	priority_queue<int,vector<int>,greater<int>> qt;
	for (int i = 0; i < n; ++i) {
		
		for (int j = 0; j < n; ++j) {
			int s;
			cin >> s;
			qt.push(s);
		}

		while (qt.size() > n) {
			qt.pop();
		}
	}
	printf("%d", qt.top());
}