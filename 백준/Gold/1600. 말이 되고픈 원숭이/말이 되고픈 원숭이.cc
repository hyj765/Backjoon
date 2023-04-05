#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool visit[200][200][31];
int reach = INT32_MAX;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int jumpx[] = { 2,2,-2,-2,1,-1,1,-1 };
int jumpy[] = { 1,-1,-1,1,2,2,-2,-2 };
int n, m;
void simulate(const vector<vector<int>> &map,const int &k) {
	queue<pair<pair<int,int>,pair<int,int>>> qu;
	qu.push({{ 0, 0 }, { 0, 0 }});
	visit[0][0][0] = true;
	while (!qu.empty()) {
		int x = qu.front().first.first;
		int y = qu.front().first.second;
		int j = qu.front().second.first;
		int d = qu.front().second.second;
		qu.pop();
		if (x == n - 1 && y == m - 1) {
			reach = d;
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == 1) continue;
			if (visit[nx][ny][j]) continue;
			visit[nx][ny][j] = true;
			qu.push({ { nx,ny},{j,d + 1} });
		}
		if (j < k) {
			for (int i = 0; i < 8; ++i) {
				int nx = x + jumpx[i];
				int ny = y + jumpy[i];
				if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
				if (map[nx][ny] == 1) continue;
				if (visit[nx][ny][j+1]) continue;
				visit[nx][ny][j + 1] = true;
				qu.push({ {nx,ny},{j + 1,d + 1}});
			}
		}

	}
}



int main() {
		
	int k;
	
	cin >> k;
	cin >> m >>n;
	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	simulate(map, k);
	if (reach == INT32_MAX) printf("-1");
	else printf("%d", reach);
}