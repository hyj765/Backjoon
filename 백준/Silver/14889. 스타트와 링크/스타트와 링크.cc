#include<iostream>
#include<algorithm>
using namespace std;

bool teams[20] = { false, };
int minimalized_int = INT32_MAX;
void solution(int depth, const vector<vector<int>>& map,int count,int n) {
	if (count == n/2) {
		int left = 0;
		int right = 0;
		for (int i = 0; i < n; ++i) {
			if (!teams[i]) continue;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (!teams[j]) continue;
				left += map[i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			if (teams[i]) continue;
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				if (teams[j]) continue;
				right += map[i][j];
			}
		}
		//printf("%d %d = %d\n", left, right, abs(left-right));
		minimalized_int = minimalized_int > abs(left - right) ? abs(left - right) : minimalized_int;
		return;
	}
	if (depth == n) return;
	teams[depth] = true;
	solution(depth + 1, map, count+1, n);
	teams[depth] = false;
	solution(depth + 1, map, count, n);

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> map(n,vector<int>(n,0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	solution(0, map, 0, n);
	printf("%d", minimalized_int);
}