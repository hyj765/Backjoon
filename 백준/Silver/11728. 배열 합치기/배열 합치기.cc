#include<iostream>
#include<vector>
#include<queue>

/* 
	백준 11728 배열 합치기
	A, B 두개의  정수형 배열이 주어질 때 이를 합치고 이를 정렬하여 배열 반환
	첫 줄에는 벡터 a의 크기와 벡터 b의 크기가 주어짐
	vector_conbine(vector<int> a, vector<int> b)

*/

void vector_value_init(std::vector<int> &t,int n) {
	int num;
	t.reserve(30000000);
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		t.push_back(num);
	}
	t.shrink_to_fit();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a, b;
	vector_value_init(a, n);
	vector_value_init(b, m);
	a.insert(a.end(), b.begin(), b.end());
	std::priority_queue<int,std::vector<int>,std::greater<int>> r(a.begin(),a.end());
	while (!r.empty()) {
		std::cout << r.top() << " ";
		r.pop();
	}
}