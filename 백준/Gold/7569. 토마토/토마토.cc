#include<iostream>
#include<vector>
using namespace std;
int n, m, h;
int dir[6][3] = {
	{ 0,0,1 },
	{ 0,1,0},
	{ 0,0,-1},
	{ 0,-1,0},
	{ 1,0,0},
	{-1,0,0}
};

bool isZeroExist(const vector<vector< vector<int>>> & pan) {
	bool flag = false;
	for (int k = 0; k < pan.size(); ++k) {
		for (int i = 0; i < pan[0].size(); ++i) {
			for (int j = 0; j < pan[0][0].size(); ++j) {
				if (pan[k][i][j] == 0) {
					flag = true;
					break;
				}
			}
		}
	}

	return flag;
}

int ZeroCount(const vector<vector< vector<int>>>& pan) {
	int zero = 0;
	for (int k = 0; k < pan.size(); ++k) {
		for (int i = 0; i < pan[0].size(); ++i) {
			for (int j = 0; j < pan[0][0].size(); ++j) {
				if (pan[k][i][j] == 0) { zero++; }
			}
		}
	}

	return zero;
}

vector<vector<int>> bfs(vector<vector<vector<int>>>& pan, const vector<vector<int>> &tomatos) {
	vector<vector<int>> temp;
	for (vector<int> tomato:tomatos) {
		for (int i = 0; i < 6; ++i) {
			int nz = tomato[0] + dir[i][0];
			int nx = tomato[1] + dir[i][1];
			int ny = tomato[2] + dir[i][2];
			if (nz >= h || nz < 0 || nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			if (pan[nz][nx][ny] == 1 || pan[nz][nx][ny] == -1) continue;
			pan[nz][nx][ny] = 1;
			temp.push_back({ nz,nx,ny });
		}
	}
	return temp;
}

void printMatrix(const vector<vector<int>> mat) {
	for (int i = 0; i < mat.size(); ++i) {
		for (int j = 0; j < mat[0].size(); ++j) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int simulate(vector<vector<vector<int>>> &pan, vector<vector<int>>& tomatos) {
	int timer = 0;
	int znt = -1;
	vector<vector<vector<int>>> map;
	// 최대 루프 100번 이상 시 터짐.
	while (true) {
		tomatos=bfs(pan,tomatos);
		// grow
		
		if (tomatos.size() == 0) {
			break;
		}
		//printMatrix(pan[0]);
		//printMatrix(pan[1]);
		timer++;
	}

	if (isZeroExist(pan)) {
		return -1;
	}
	return timer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n >> h;
	vector<vector<int>> tomatos;
	vector<vector<vector<int>>> pan;
	for (int k = 0; k < h; ++k) {
		vector<vector<int>> mat;
		for (int i = 0; i < n; ++i) {
			vector<int> line;
			for (int j = 0; j < m; ++j) {
				int tomato;
				cin >> tomato;
				line.push_back(tomato);
				if (tomato == 1) {
					tomatos.push_back({ k,i,j });
				}
			}
			mat.push_back(line);
		}
		pan.push_back(mat);
	}

	/*
	for (int i = 0; i < tomatos.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", tomatos[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d", simulate(pan,tomatos));
}