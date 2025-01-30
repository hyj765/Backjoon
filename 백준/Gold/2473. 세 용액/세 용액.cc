#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

int main()
{
	ll answer = INT64_MAX;
	ll af, as, at;

	int n;
	cin >> n;

	vector<ll> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 2; ++i)
	{
		int left = i + 1;
		int right = n - 1;
		while (left < right)
		{
			ll value = arr[i] + arr[left] + arr[right];
			if (value == 0)
			{
				af = arr[i];
				as = arr[left];
				at = arr[right];
				break;
			}

			if (abs(value) < abs(answer))
			{
				answer = value;
				af = arr[i];
				as = arr[left];
				at = arr[right];
			}

			if (value < 0)
			{
				left++;
			}
			else {
				right--;
			}

		}
	}

	printf("%lld %lld %lld", af,as,at);
}