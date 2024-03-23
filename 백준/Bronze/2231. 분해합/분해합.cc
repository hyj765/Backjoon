#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getCont(int n) {
	int temp = n;
	while (n > 0) {
		int mod=n % 10;
		n /= 10;
		temp += mod;
	}
	return temp;
}

int main() {

	int n;
	int answer = 0;
	cin >> n;
	int temp = n;
	while (n > 0) {
		n--;

		if (getCont(n) == temp) {
			answer = n;
		}


	}

	cout << answer;
}