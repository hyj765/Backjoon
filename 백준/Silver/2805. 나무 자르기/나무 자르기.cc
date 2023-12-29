#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long



int main() {

	ll n, m;
	cin >> n >> m;
	ll minvl=0,maxvl;
	vector<int> arr(n);
	
	for (int i = 0; i < arr.size(); ++i) {
		cin >> arr[i];
	}
	maxvl = *max_element(arr.begin(), arr.end());
	ll answer = 0;

	while (minvl <= maxvl) {
		ll vl = 0;
		ll middle = (minvl + maxvl) / 2;
		
		for (int i = 0; i < arr.size(); ++i) {
			if (arr[i] > middle) {

				vl += (arr[i] - middle);
			}
		}

		if (vl >= m) {
			answer = max(middle, answer);
			minvl = middle + 1;
		}
		else {
			maxvl = middle - 1;
		}
	}

	cout << answer;
}