#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool check[25];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int answer = 0;

bool isConnected(int start)
{
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(5,vector<bool>(5));
	q.push({ start / 5, start % 5 });
	visit[start / 5][start % 5] = true;
	int cnt = 0;

	while (!q.empty() )
	{
		auto cur = q.front();
		q.pop();
		cnt++;

		if (cnt == 7)
		{
			return true;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx >= 5 || ny >= 5 || nx < 0 || ny < 0) continue;
			if (visit[nx][ny] == true) continue;
			if (check[nx * 5 + ny] == false) continue;
			
			visit[nx][ny] = true;
			q.push({ nx,ny });
			
		}
	}

	return false;

}



void choose(int depth,int s,  const vector<vector<char>>& map,int start)
{
	if (depth == 7)
	{
		if (s >= 4)
		{
			if (isConnected(start))
			{
				answer++;
			}
		}
	}

	for (int i = start; i < 25; ++i)
	{
		if (check[i]) continue;

		check[i] = true;
		if (map[i / 5][i % 5] == 'S') {
			choose(depth + 1, s + 1, map, i);
		}
		else {
			choose(depth + 1, s, map, i);
		}
		check[i] = false;
	}
}



int main()
{
	

	vector<vector<char>> map(5, vector<char>(5));
	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cin >> map[i][j];
		}
	}

	choose(0, 0, map,0);

	cout << answer;

}