#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool flag = false;
	string te;
	getline(cin , te );
	
	stack<char> buffer;

	for (int i = 0; i <= te.size(); ++i) {
		
		if (te[i] == '<') {
			while (!buffer.empty()) {
				cout << buffer.top();
				buffer.pop();
			}
			while (1) {
				cout << te[i];
				if (te[i] == '>') break;
				++i;
			}
		}
		else if(te[i] == ' ' || i == te.size()) {
			while (!buffer.empty()) {
				cout << buffer.top();
				buffer.pop();
			}
			if (i == te.size()) break;
			cout << ' ';
		}
		else {
			buffer.push(te[i]);
		}
	}

}