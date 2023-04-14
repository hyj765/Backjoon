#include<iostream>
#include <vector>
#include <string>
using namespace std;




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string v;
	cin >> v;
	
	bool isMinus = false;
	string temp;
	int n = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] != '-' && v[i] != '+') temp += v[i];
		else {
			if (isMinus) {
				n -= atoi(temp.c_str());
			}
			else {
				n += atoi(temp.c_str());
			}
			temp.clear();
		}
		if (v[i] == '-') {
			isMinus = true;
		}
		if (i == v.size() - 1) {
			if (isMinus) {
				n -= atoi(temp.c_str());
			}
			else {
				n += atoi(temp.c_str());
			}
		}
	}
	
	printf("%d",n);

	return 0;
}