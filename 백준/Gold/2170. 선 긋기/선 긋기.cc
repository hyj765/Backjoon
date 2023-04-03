#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int min = INT32_MAX;
	int max = 0;
	vector<pair<int, int>> line;
	vector<pair<int, int>> totalline;
	line.reserve(1000000);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		line.push_back({ x,y });
	}
	
	sort(line.begin(), line.end());

	min = line[0].first;
	max = line[0].second;
	if (n == 1) {
		printf("%d", (max - min));
		return 0;
	}

	for (int i = 1; i < n; ++i) {
		if (max < line[i].first) {
			totalline.push_back({ min,max });
			min = line[i].first;
			max = line[i].second;
			continue;
		}
		max = max < line[i].second ? line[i].second : max;
	}
	totalline.push_back({ min,max });
	int total = 0;
	for (pair<int, int> li : totalline) {
		total += (li.second - li.first);
		
	}
	
	printf("%d", total);
	
	return 0;
}