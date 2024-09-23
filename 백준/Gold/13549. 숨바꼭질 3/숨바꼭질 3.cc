#include<iostream>
#include<queue>
using namespace std;

int speed = 100001;

bool visit[100001];

struct compare
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}

};


int main()
{
	

	int n, m;

	cin >> n >> m;

	if (n == m)
	{
		cout << 0;
		return 0;
	}

	priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;
	
	q.push({n,0});

	while (!q.empty())
	{
		int x = q.top().first;
		int time = q.top().second;
		q.pop();

		visit[x] = true;
		
		if (x == m )
		{
			speed = time;
			break;
		}


		if (x + 1 <= 100000 && visit[x + 1] == false)
		{
			q.push({ x + 1, time + 1 });
			
		}

		if (x - 1 >= 0 && visit[x - 1] == false)
		{
			q.push({ x - 1, time + 1 });
		}

		if (x * 2 <= 100000 && x * 2 > 0 && visit[x * 2] == false)
		{
			q.push({ x * 2,time });
		}


	}

	cout << speed;
}