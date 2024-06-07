#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long s = 0;
	int n = 0;
	cin >> s;
	
	while (s >0)
	{
		n++;
		s = s - n;
	}

	if (s < 0)
	{
		n--;
	}

    cout << n << endl;

}