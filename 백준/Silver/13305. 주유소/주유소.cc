#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

#define ll long long



int main()
{
	/*
	
		1. 각자 더하는 게 짧을 수 있어.
		2. 아닌 경우 
		3. 작은 게 더 있는 경우

	*/
	long long n ,answer = 0;
	cin >> n;
	vector<ll> distance((n-1));
	vector<ll> cost(n);

	/*
		init;
	
	*/
	for (int i = 0; i < n-1; ++i)
	{
		cin >> distance[i];
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
	}
	/*

	 2 5 3 7
	4 2 3 1 100
	
	*/
	
	int cur = cost[0];
	int capdis = 0;
	for (int i = 0; i < n; ++i)
	{
		if (cur > cost[i] || i == n-1)
		{
			answer += (cur * capdis);
			if (i == n-1)
			{
				break;
			}
			cur = cost[i];
			capdis = 0;
		}
		capdis += distance[i];
	}


	cout << answer; 
}