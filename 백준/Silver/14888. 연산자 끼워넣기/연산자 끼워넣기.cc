#include<iostream>
#include<vector>
using namespace std;

vector<int> operators;
int total = 0;
long long maxvalue = -1000000000;
long long minvalue = 1000000000;

void solv(int depth, int sum, const vector<int>& arr, int calc) {

	if (total - calc == 0) {
		maxvalue = maxvalue < sum ? sum : maxvalue;
		minvalue = minvalue > sum ? sum : minvalue;
		//cout << sum << endl;
		return;
	}

	if (operators[0] > 0) {
		operators[0] -= 1;
		solv(depth + 1, sum + arr[depth], arr,calc+1);
		operators[0] += 1;
	}

	if (operators[1] > 0) {
		operators[1] -= 1;
		solv(depth + 1, sum - arr[depth], arr,calc+1);
		operators[1] += 1;
	}
	
	if (operators[2] > 0) {
		operators[2] -= 1;
		solv(depth + 1, sum * arr[depth], arr,calc+1);
		operators[2] += 1;
	}

	if (operators[3] > 0) {
		operators[3] -= 1;
		solv(depth + 1, sum / arr[depth], arr,calc+1);
		operators[3] += 1;
	}
}



int main() {


	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < 4; ++i) {
		int temp;
		cin >> temp;
		total += temp;
		operators.push_back(temp);
	}

	solv(1, arr[0], arr,0);


	cout << maxvalue << '\n' << minvalue;

}