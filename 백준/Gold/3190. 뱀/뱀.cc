#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

queue<pair<int, int>> tailQueue;

bool snakeMove(vector<vector<int>>& map, pair<int,int>& snakehead, int direction,int n)
{
	
	int nx = snakehead.first + dx[direction];
	int ny = snakehead.second + dy[direction];

	if (nx >= n || nx < 0 || ny >= n || ny < 0)
	{
		return false;
	}
	
	if (map[nx][ny] == 2)
	{
		return false;
	}

	if (map[nx][ny] == 0)
	{
		auto axis = tailQueue.front();
		tailQueue.pop();
		map[axis.first][axis.second] = 0;	

	}
	
	tailQueue.push({ nx,ny });
	map[nx][ny] = 2;
	snakehead.first = nx;
	snakehead.second = ny;
	
	return true;
}


int main()
{
	
	int n,applen;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	cin >> applen;
	for (int i = 0; i < applen; ++i)
	{
		int x, y;
		cin >> x >> y;
		map[x-1][y-1] = 1;
	}

	vector<pair<int, char>> acts;

	int act;
	cin >> act;
	for (int i = 0; i < act; ++i)
	{
		int x;
		char c;
		cin >> x >> c;
		acts.push_back({x,c});
	}
	sort(acts.begin(), acts.end());
	pair<int, int> snakehead = { 0,0 };
	map[snakehead.first][snakehead.second] = 2;

	tailQueue.push({ 0, 0 });
	int direction = 0;
	int cur = 0;
	int turn = 0;

	while (1)
	{
	

		if (cur < acts.size() && acts[cur].first == turn)
		{
			if (acts[cur].second == 'D')
			{
				direction = (direction + 1) % 4;
			}
			else if (acts[cur].second == 'L')
			{
				direction = (direction + 3) % 4;
			}
			cur++;
		}

		if (!snakeMove(map, snakehead, direction, n))
		{
			
			break;
		}

		turn++;
	}

	std::cout << turn +1  << endl;
}
