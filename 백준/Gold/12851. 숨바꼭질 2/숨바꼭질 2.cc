#include<iostream>
#include<queue>
using namespace std;

int speed = 100001;
int cnt = 0;

bool visit[100001];

int main()
{
	int n, m;

	cin >> n >> m;

	if (n == m)
	{
		cout << 0 << endl;
		cout << 1 << endl;
		return 0;
	}

	queue<pair<int,int>> q;
	q.push({n,0});
	while (!q.empty())
	{
		int x = q.front().first;
		int time = q.front().second;
		q.pop();

		visit[x] = true;
		
		if (speed < time) continue;
		
		if (x == m )
		{
			speed = time;
			cnt++;
		}


		if (x * 2 <= 100000 && x * 2 > 0 && visit[x * 2] == false)
		{
			q.push({ x * 2,time + 1 });
		}

		if (x + 1 <= 100000 && visit[x+1] == false)
		{
			q.push({ x + 1, time + 1 });
		}

		if (x - 1 >= 0 && visit[x-1] == false)
		{
			q.push({ x - 1, time + 1 });
		}

	}

	cout << speed << "\n" << cnt;
}