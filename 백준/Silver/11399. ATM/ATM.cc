#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,answer = 0;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int waittime = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += arr[i] + waittime;
		waittime += arr[i];
	}


	cout << answer;
}