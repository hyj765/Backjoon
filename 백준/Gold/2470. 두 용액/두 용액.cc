#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	
	int answer = INT32_MAX;
	int al;
	int ar;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	int l = 0;
	int r = arr.size() - 1;
	while (l < r )
	{
		int value = arr[l] + arr[r];

		if (value == 0)
		{
			al = l;
			ar = r;
			break;
		}
		else if (abs(value) < answer)
		{
			answer = abs(value);
			al = l;
			ar = r;
		}

		if (value > 0)
		{
			r--;
		}
		else {
			l++;
		}

	}

	cout << arr[al] << " " << arr[ar];
}