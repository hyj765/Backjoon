#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int count = 0;
	int n,m;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	// 1 2 3 4 5 6 7 7 7 7
	cin >> m;

	sort(arr.begin(), arr.end());

	int start = 0;
	int end = arr.size() - 1;

	while (start < end)
	{
		int middle = arr[start] + arr[end];
		if (middle == m)
		{
			count++;
		}

		if (middle > m)
		{
			end--;
		}
		else {
			start++;
		}

	}

	cout << count;
}