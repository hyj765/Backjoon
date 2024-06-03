#include<iostream>
#include<vector>
#include<set>
using namespace std;

int chbox[100001];
int main()
{

	int n, m;
	int answer = 0;
	int left = 0, right = 0;
	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	
	while (right < n && left <= right)
	{

		if (chbox[arr[right]] < m)
		{
			chbox[arr[right++]]++;
			answer = max(answer, right - left);
		}
		else if(chbox[arr[right]] == m)
		{
			chbox[arr[left++]]--;
		}
	}

	cout << answer;

}