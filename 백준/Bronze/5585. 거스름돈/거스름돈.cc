#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int coins[] = { 500,100,50,10,5,1 };
	int n;
	cin >> n;
	n = 1000 - n;
	int answer = 0;


	for (int i = 0; i < 6; ++i)
	{
		if (coins[i] <= n)
		{
			answer += (n / coins[i]);
			n %= coins[i];
		}
	}

	cout << answer;

}