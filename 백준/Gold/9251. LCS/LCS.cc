#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a;
	cin >> b;

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) n[i][j] = n[i - 1][j - 1] + 1;
			else {
				n[i][j] = n[i - 1][j]> n[i][j - 1] ? n[i - 1][j] : n[i][j - 1];
			}
		}
	}
	cout << n[a.size()][b.size()];	
}