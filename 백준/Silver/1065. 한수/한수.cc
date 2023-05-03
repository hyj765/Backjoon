#include<iostream>
#include<string>
using namespace std;

bool check(int n) {

	if (n < 100) return true;

	int n1 = n / 100; // 100 자리

	int n2 = n % 100 / 10; // 10의 자리

	int n3 = n % 10; // 1의 자리	
	if (n1 - n2 == n2 - n3) return true;
	return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int i = 1;
	int cnt = 0;
	while (i <= n) {
		if (check(i)) {
			cnt++;
		}
		i++;
	}
	cout << cnt;
}