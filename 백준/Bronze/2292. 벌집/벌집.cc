#include<iostream>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int cnt = 1;
	int temp = 1;

	while (temp < n)
	{
		temp  += (6 * cnt);
		cnt++;
	}

	cout << cnt;
	return 0;
}