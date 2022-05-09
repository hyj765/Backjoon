#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> solution(const std::vector<int> y) {
	std::vector<int> answer;
	std::vector<int> liar(2);
	int total = 100;
	int size = y.size();
	for (int i = 0; i < size; i++) {
		total -= y[i];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (total + (y[i] + y[j]) == 0) {
				liar[0] = i;
				liar[1] = j;
				break;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (i == liar[0] || i == liar[1]) continue;
		answer.push_back(y[i]);
	}

	return answer;
}

int main() {
	std::vector<int> littles(9,0);
	for (int i = 0; i < 9; i++) {
		std::cin >> littles[i];
	}
	sort(littles.begin(),littles.end());
	std::vector<int> result = solution(littles);
	for (int val : result) {
		std::cout << val << '\n';
	}
}