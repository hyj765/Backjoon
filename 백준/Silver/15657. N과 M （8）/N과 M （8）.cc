#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> value(8);
void simulate(vector<int> arr, int depth,int m ,int start){
	
	if (depth == m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", value[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < arr.size(); ++i) {
		
		value[depth] = arr[i];
		simulate(arr, depth + 1, m, i);

	}


}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	vector<bool> visit(n);
	sort(arr.begin(), arr.end());

	simulate(arr, 0, m,0);

}