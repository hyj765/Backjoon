#include<iostream>
#include<vector>
#include<queue>
using namespace std;

char map[50][50];
bool visit[50][50][64];
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int keys[] = { 1,2,4,8,16,32 };
int bfs(int x, int y) {

	queue<vector<int>> q;
	q.push({ x,y,0,0 });
	
	while (!q.empty()) {
		int cx = q.front()[0];
		int cy = q.front()[1];
		int t = q.front()[2];
		int div = q.front()[3];
		q.pop();
		if (map[cx][cy] >= 97 && map[cx][cy] <= 102) {
			div |= keys[map[cx][cy] - 97];
		}
		if (map[cx][cy] == '1') return t;
		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (map[nx][ny] == '#') continue;
			if (visit[nx][ny][div]) continue;
			if (map[nx][ny] >= 65 && map[nx][ny] <= 70) {
				if ((keys[map[nx][ny] - 65] & div) == 0) continue;
			}
			visit[nx][ny][div] = true;
			q.push({ nx,ny,t + 1,div });
		}
	}

	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c = cin.get();
			if (c == '\n') c = cin.get();
			map[i][j] = c;
			if (map[i][j] == '0') {
				x = i;
				y = j;
			}
		}

	}

	int r = bfs(x, y);
	printf("%d", r);
	return 0;
}