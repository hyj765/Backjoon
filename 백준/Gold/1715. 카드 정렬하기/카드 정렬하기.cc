#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

#define ll long long



int main()
{
	
	
	ll answer = 0;
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> arr;
	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		arr.push(temp);
	}
	
	while (arr.size() > 1)
	{
		int first = arr.top();
		arr.pop();
		int second = arr.top();
		arr.pop();
		arr.push(first + second);
		answer += first + second;
	}


	cout << answer; 
}