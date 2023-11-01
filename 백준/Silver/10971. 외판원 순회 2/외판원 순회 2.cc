#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool visit[10];
int minv = 99999999;
void solv(int depth,int n,const vector<vector<int>>& temp, int val,int cur,int first) {
	
	
	if (depth == n-1) {
		if (temp[cur][first] == 0) return;
		int r = val + temp[cur][first];
		minv = minv > r ? r : minv;
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (temp[cur][i] == 0) continue;
		if (!visit[i]) {
			visit[i] = true;
			int tv = val + temp[cur][i];
			solv(depth + 1, n, temp, tv,i,first);
			visit[i] = false;
		}

	}


}



int main() {

	int n;
	cin >> n;

	vector<vector<int>> map(n,vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}

	for (int i = 0; i < n; ++i) {
		visit[i] = true;
		solv(0, n, map, 0,i,i);
		visit[i] = false;
	}

	cout << minv << endl;
}