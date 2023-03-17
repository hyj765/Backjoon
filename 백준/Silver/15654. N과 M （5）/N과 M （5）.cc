#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> value(8);
void simulate(vector<int> arr, int depth,int m ,vector<bool> visit){
	
	if (depth == m) {
		for (int i = 0; i < m; ++i) {
			printf("%d ", value[i]);
		}
		printf("\n");
	}
	for (int i = 0; i < arr.size(); ++i) {
		if (visit[i]) continue;
		visit[i] = true;
		value[depth] = arr[i];
		simulate(arr, depth + 1, m, visit);
		visit[i] = false;
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

	simulate(arr, 0, m, visit);

}