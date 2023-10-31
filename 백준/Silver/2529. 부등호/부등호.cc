#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int ready[10];
bool visit[10];

int cnt = 0;
int result[10];
int minre[10];
void solv(int depth, int n, const vector<char>& v) {

	if (depth == n) {

		if (cnt == 0) {
			for (int i = 0; i < n + 1; ++i) {
				minre[i] = ready[i];
			}
			cnt++;
		}

		for (int i = 0; i < n + 1; ++i) {
			result[i] = ready[i];
		}
		return;
	}

	for (int i = 0; i < 10; ++i) {	
		if (v[depth] == '>') {
			if (ready[depth] > i) {
				if (!visit[i]) {
					visit[i] = true;
					ready[depth+1] = i;
					solv(depth + 1, n, v);
					visit[i] = false;
				}
			}
		}
		else {
			if (ready[depth] < i) {
				if (!visit[i]) {
					visit[i] = true;
					ready[depth+1] = i;
					solv(depth + 1, n, v);
					visit[i] = false;
				}
			}
		}
	}

}






int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<char> ch(n);
	for (int i = 0; i < n; ++i) {
		cin >> ch[i];
	}

	for (int i = 0; i < 10; ++i) {
		ready[0] = i;
		visit[i] = true;
		solv(0, n, ch);
		visit[i] = false;
	}

	
	for (int i = 0; i < n + 1; ++i) {
		cout << result[i];
	}
	cout << '\n';
	for (int i = 0; i < n + 1; ++i) {
		cout << minre[i];
	}

}