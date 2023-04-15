#include<iostream>
#include<queue>
using namespace std;

struct abs_cmp {
	bool operator()(int &a, int &b){
		
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};



int main() {
	int n;
	priority_queue<int,vector<int>,abs_cmp> qt;
	cin >> n;
	int value;
	for (int i = 0; i < n; ++i) {
		cin >> value;
		if (value != 0) {
			qt.push(value);
		}
		else {
			if (!qt.empty()) {
				printf("%d\n", qt.top());
				qt.pop();
			}
			else {
				printf("0\n");
			}
		}
	}
	

}