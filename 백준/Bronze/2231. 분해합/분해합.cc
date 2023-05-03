#include<iostream>
#include<string>
using namespace std;

int constructor(int n) {
	int temp = n;
	string st = to_string(n);
	for (int i = 0; i < st.size(); ++i) {
		temp += st[i] - '0';
	}
	return temp;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int i = 1;
	int answer = 0;
	while (i < n) {

		if (constructor(i) == n) {
			answer = i;
			break;
		}
		i++;
	}

	cout << answer;
}