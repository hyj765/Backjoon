#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

#define ll long long

bool compare(pair < ll , ll > a, pair< ll , ll> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main()
{
	int answer = 0;
	int n;
	vector<pair<ll, ll>> s;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a1, a2;
		cin >> a1 >> a2;
		s.push_back(make_pair(a1,a2));
	}

	sort(s.begin(), s.end(),compare);
	
	stack<ll> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (st.empty())
		{
			//cout << s[i].first << " " << s[i].second << endl;
			st.push(s[i].second);
			answer++;
			continue;
		}
		if (st.top() <= s[i].first)
		{
		//	cout << s[i].first << " " << s[i].second << endl;
			st.push(s[i].second);
			answer++;
		}

	}

	cout << answer;
}