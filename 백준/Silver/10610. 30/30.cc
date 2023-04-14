#include<iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;


bool isMultiple(const int &x) {
	if (x % 30 == 0) return true;
	return false;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string v;
	cin >> v;
	sort(v.begin(), v.end(),greater<>());
	if (v[v.length() - 1] != '0') {
		printf("-1");
		return 0;
	}
	long long n = 0;
	for (auto w : v) {
		n += w - '0';
	}
	
	if (n % 3 == 0) {
		printf("%s", v.c_str());
	}
	else {
		printf("-1");
	}

	return 0;
}