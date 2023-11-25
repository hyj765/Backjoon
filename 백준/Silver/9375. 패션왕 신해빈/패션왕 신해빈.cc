#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {

	int T;
	cin >> T;
	
	vector<string> str;
	string name, type;

	for (int j = 0; j < T; ++j) {
		map<string, int> s;
		int n;
		cin >> n;
		int answer = 1;
		for (int i = 0; i < n; ++i) {
			cin >> name >> type;

			s[type]++;

		}
		for (pair<string, int> val : s) {
			answer *= val.second + 1;
		}
			
		
		answer--;
		cout << answer << endl;
	}
}