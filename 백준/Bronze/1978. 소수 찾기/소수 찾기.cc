#include<iostream>
#include<vector>
using namespace std;


bool prime(int n) {
	if (n == 1) return false;

	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n , answer = 0;
	cin >> n;
	vector<int> arr; 

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < n; ++i) {
		if (prime(arr[i])) {
			answer++;
		}
	}

	cout << answer;


}