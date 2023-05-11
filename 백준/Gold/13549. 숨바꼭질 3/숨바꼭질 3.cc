#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 1 2

int myturn = INT32_MAX;
void bfs(int n, int m) {
	if (n == m) {
		myturn = 0;
		return;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	que.push({ 0,n });
	vector<bool> visit(100001, false);

	while (!que.empty()) {
		int turn = que.top().first;
		int cur = que.top().second;
		que.pop();
		visit[cur] = true;
		if (cur == m) {
			myturn = turn;
			return;
		}
		if (cur - 1 >= 0 && !visit[cur - 1]) que.push({ turn + 1, cur - 1 });
		if (cur + 1 <= 100000 && !visit[cur + 1]) que.push({ turn + 1, cur + 1 });
		if (cur *2 <= 100000 && !visit[cur *2]) que.push({ turn, cur *2 });
	}
}





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	bfs(n, m);
	cout << myturn;
}