#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

	long long x, y;
	cin >> x >> y;
	int z = (y * 100 / x);
	if (z >= 99) {
		printf("-1");
		return 0;
	}
	int start = 0;
	int end = 1000000000;
	int r = 0;
	while (start <= end) {

		int middle = (start + end) / 2;

		int nz = ((y + middle) * 100 / (x + middle));
		if (nz > z) {
			end = middle - 1;
		}
		else {

			r = middle + 1;
			start = middle + 1;

		}
	}
	

	printf("%d", r);
}