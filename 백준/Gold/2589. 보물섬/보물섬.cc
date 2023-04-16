#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[50][50];
int maximalized_int = 0;
char map[50][50];
void bfs(int x, int y) {
	
	queue<vector<int>> qt;
	visit[x][y] = true;
	qt.push({ x,y,0 });
	while (!qt.empty()) {
		int x = qt.front()[0];
		int y = qt.front()[1];
		int d = qt.front()[2];
		qt.pop();
		if (d > maximalized_int) {
			//printf("%d %d %d\n", x, y,d);
			maximalized_int = d;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == 'W') continue;
			if (visit[nx][ny]) continue;
			visit[nx][ny] = true;
			qt.push({ nx,ny,d + 1 });
		}



	}

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char temp = cin.get();
			if (temp == '\n') {
				temp = cin.get();
			}
			map[i][j] = temp;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 'W') continue;
			bfs(i, j);
			memset(visit, false, sizeof(visit));
		}
	}

	printf("%d", maximalized_int);

}