#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int answer = 0;
	int temp = 0;
	int i = 0;
	
	for (int i = 1; i <= n; ++i) 
	{
		
		int temp = 0;

		for (int j = i; j <= n; ++j)
		{
			temp += j;
			if (temp >= n)
			{
				if (temp == n)
				{
					answer++;
				}
				break;
			}
			
		}
	}

	cout << answer;

}