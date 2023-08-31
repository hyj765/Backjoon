#include <iostream>
#include<vector>
using namespace std;

const char* temp1[] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
const char* temp2[] = { 
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int check(const vector<vector<char>>& map, int axis1, int axis2, bool type) {
	int cnt = 0;
	if (type) {
		for (int i = axis1; i < axis1 + 8; ++i) {
			for (int j = axis2; j < axis2 + 8; ++j) {
				if (temp1[i % 8][j % 8] != map[i][j]) {

					cnt++;
				}
			}
		}
	}
	else {
		for (int i = axis1; i < axis1 + 8; ++i) {
			for (int j = axis2; j < axis2 + 8; ++j) {
				if (temp2[i % 8][j % 8] != map[i][j]) {
					cnt++;
				}
			}
		}
	}

	return cnt;
}

void rolling(vector<vector<char>> map,int n,int m) {
	int flag = 0;
	int cnt = INT32_MAX;

	for (int i = 0; i <= n -8; ++i) {
		for (int j = 0; j <= m - 8; ++j) {
			int r = check(map, i, j, true);
			int s = check(map, i, j, false);
			//cout << r << " " << s << endl;
			if (r > s) r = s;
			cnt = cnt > r ? r : cnt;
		}
	}
    
	cout << cnt << endl;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> map(n,vector<char>(m));

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); ++j) {
			map[i][j] = s[j];
		}
	}
	
	rolling(map, n, m);
}
