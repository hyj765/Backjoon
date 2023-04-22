#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool map[16][16];
int cnt;

bool check(int x,int y,int n) {

	for (int i = 0; i < n; ++i) {
		if (map[x][i]) return false; // 행 전부 체크
		if (map[i][y]) return false; // 열 전부 체크
	}

	for (int i = 0; i < n; ++i) {
		int nx = x + i;
		int mx = x - i;
		int ny = y + i;
		int my = y - i;
		//if (nx >= n || mx < 0 || ny >= n || my < 0) continue;
		if (nx < n && ny < n) {
			if (map[nx][ny]) return false; // 오른쪽 대각 아래 4/4
		}
		if (mx >= 0 && my >= 0) {
			if (map[mx][my]) return false; // 왼쪽 대각 위 1/4
 		}
		if (mx >= 0 && ny < n) {
			if (map[mx][ny]) return false; // 2/4
		}
		if (my >= 0 && nx < n) {
			if (map[nx][my]) return false;// 3/4
		}

	}// >>>>> 대각


	return true;
}

void simulate(int depth,int n) {

	if (depth == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (check(depth, i,n)) {
			map[depth][i] = true;
			simulate(depth + 1, n);
			map[depth][i] = false;
		}
	}


}





int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	simulate(0, n);
	printf("%d", cnt);
}
