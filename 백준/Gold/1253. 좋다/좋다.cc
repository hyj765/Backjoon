#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main()
{
	
	int count = 0;
	
	int n;
	cin >> n;
	map<int, int> dptable;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dptable[arr[i]]++;
	}

	
	sort(arr.begin(), arr.end());
	int maximum = arr[arr.size() - 1];
	

	for (int i = 0; i < n; ++i)
	{
		if (dptable[arr[i]] == 0)
		{
			continue;
		}
		int value = arr[i];
		int left = 0;
		int right = n - 1;
		while (left < right)
		{
			int sum = arr[left] + arr[right];
			if (sum == value)
			{
				if (left != i && right != i )
				{
					count += dptable[sum];
					dptable[sum] = 0;
					break;
				}
				else if (left == i)
				{
					left++;
				}
				else {
					right--;
				}
			}
			else if (sum < value)
			{
				left++;
			}
			else {
				right--;
			}
		}
	}


	cout << count;
}