#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), greater<int>());

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > m)
		{
			continue;
		}

		if (m == 0)
		{
			break;
		}

		answer += ( m / arr[i]);
		m %= arr[i];

	}

	cout << answer;

}