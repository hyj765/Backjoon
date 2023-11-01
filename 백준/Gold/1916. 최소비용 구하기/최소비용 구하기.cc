#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

/*
	n: a number of city 
	m: a number of bus


*/


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> city(n+1,vector<int>(n+1,99999999));

	for (int i = 0; i < m; ++i) {
		int src, dst, weight;
		cin >> src >> dst >> weight;
		if (city[src][dst] > weight) {
			city[src][dst] = weight;
		}
	}

	int cmdsrc, cmddst;

	cin >> cmdsrc >> cmddst;
	vector<bool> visit(n + 1);
	vector<int> dist(n+1, 99999999);
	dist[cmdsrc] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
	q.push({ 0,cmdsrc });
	while (!q.empty()) {
		int cur = q.top().second;
		q.pop();
		if (visit[cur]) continue;
		visit[cur] = true;
		
		for (int i = 1; i <= n; ++i) {
			if (dist[i] > dist[cur] + city[cur][i]) {
				dist[i] = dist[cur] + city[cur][i];
				q.push({dist[i],i});
			}
		}
	}


	cout << dist[cmddst];

}