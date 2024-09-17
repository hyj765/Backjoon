#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int>> zeros;
vector<vector<int>> map(9, vector<int>(9));

bool endf = false;

bool check(int x,int y, int value)
{
	for (int i = 0; i < 9; ++i)
	{
		if (map[x][i] == value)
		{
			return false;
		}

		if (map[i][y] == value)
		{
			return false;
		}
	}
	
	int lx = (x / 3) * 3;
	int ly = (y / 3) * 3;

	for (int i = lx; i < lx + 3; ++i)
	{
		for (int j = ly; j < ly + 3; ++j)
		{
			if (map[i][j] == value )
			{
				return false;
			}
		}
	}

	return true;

}

void _print()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
}


void simulate(int idx)
{
	if (endf) return;
	if (idx == zeros.size())
	{
		_print();
		endf = true;
		return;
	}
	
	int x = zeros[idx].first;
	int y = zeros[idx].second;

	for (int i = 1; i <= 9; ++i)
	{
		if (check(x, y, i))
		{
			map[x][y] = i;
			simulate(idx+1);
			map[x][y] = 0;
		}

	}



}



int main()
{
	for (int i = 0; i < 9; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 9; ++j)
		{
			map[i][j] = str[j] - '0';
			if (map[i][j] == 0)
			{
				zeros.push_back({i,j});
			}
		}
	}

	simulate(0);

}