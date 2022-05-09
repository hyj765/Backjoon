#include<iostream>
#include<vector>


int main() {
	long long n, m,cnt=100000;
	std::cin >> n >> m;
	std::vector<long long> arr(100001,0);
	bool changed = false;
	long num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		arr[i]=num;
	}
	int start = 0, end = 0;
	int sum = 0;
	while ( end <= n) {
		if (sum< m) sum +=arr[end++];
		else if(sum >=m) {
			changed = true;
			if (cnt > (end - start)) cnt = (end - start); // 0 -- 3         4개 end - start + 1         1 3 ==   4 7 10 15    
			sum -= arr[start++];
		}
	}
	if (changed) std::cout << cnt;
	else std::cout << 0;
}