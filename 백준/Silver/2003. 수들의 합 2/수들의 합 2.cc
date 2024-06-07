#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int answer = 0;

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int left = 0, right = 0;
	int sum = arr[0];

	while (right < n)
	{
		if (sum < m)
		{
			right++;
			if (right < n)
			{
				sum += arr[right];
			}
		}
		else if (sum > m)
		{
			sum -= arr[left];
			left++;
		}
		else if (sum == m)
		{
			sum -= arr[left];
			left++;
			right++;

			if (right < n)
			{
				sum += arr[right];
			}
			answer++;
		}
	}

	cout << answer;
}