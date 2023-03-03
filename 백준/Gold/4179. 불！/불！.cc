#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int MINVALUE = UINT32_MAX;

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };
bool _mapCheck(vector<vector<char>> map) {
	bool status = false;
	for (int i = 0; i < n; ++i) {
		if (map[i][0] != '#' || map[i][m - 1] != '#') {
			status = true;
			break;
		}
	}
	if (status) {
		goto exit;
	}
	for (int i = 0; i < m; ++i) {
		if (map[0][i] != '#' || map[n - 1][i] != '#') {
			status = true;
			break;
		}

	}
exit:
	return status;
}

void simulate(vector<vector<char>> map, int startx, int starty, vector<pair<int,int>> fireArray) {

	if (!_mapCheck(map)) return;
	vector<vector<int>> firemap(n, vector<int>(m,99999));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	vector<vector<bool>> firevisit(n, vector<bool>(m, false));
	queue<vector<int>> qt;
	queue<pair<int, int>> fire;
	for (pair<int, int> v : fireArray) {
		fire.push({ v.first,v.second });
		firemap[v.first][v.second] = 0;
		firevisit[v.first][v.second] = true;
	}
	while (!fire.empty()) {
		int x =fire.front().first;
		int y =fire.front().second;
		fire.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (firevisit[nx][ny]) continue;
			if (map[nx][ny] == '#') continue;
			firemap[nx][ny] = firemap[x][y] + 1;
			fire.push({ nx,ny });
			firevisit[nx][ny] = true;
		}
	}
	
	qt.push({ startx,starty,0 });
	visit[startx][starty] = true;
	while (!qt.empty()) {

		int x = qt.front()[0];
		int y = qt.front()[1];
		int t = qt.front()[2];
		qt.pop();
		if (x >= n || x < 0 || y >= m || y < 0) {
			MINVALUE = t;
			return;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= n || nx < 0 || ny >= m || ny < 0) {
				qt.push({ nx,ny,t + 1 });
				continue;
			}
			if(map[nx][ny] == '#') continue;
			if(visit[nx][ny]) continue;
			if (firemap[nx][ny] <= t+1) continue;
			qt.push({ nx,ny,t + 1 });
			visit[nx][ny] = true;
		}


	}
	
}


int main() {

	cin >> n >> m;
	vector<vector<char>> map;
	int firex = -1, firey = -1;
	int startx = -1, starty = -1;
	vector<pair<int, int>> fire;
	for (int i = 0; i < n; ++i) {
		vector<char> line;
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			line.push_back(c);
			if (c == 'F') {
				firex = i;
				firey = j;
				fire.push_back({ i,j });
			}
			else if (c == 'J') {
				startx = i;
				starty = j;
			}
		}
		map.push_back(line);
	}



	simulate(map, startx, starty,fire);

		if (MINVALUE == UINT32_MAX) {
			printf("IMPOSSIBLE");
		}
		else {
			printf("%d", MINVALUE);
		}

}