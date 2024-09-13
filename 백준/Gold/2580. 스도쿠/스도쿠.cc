#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> map(9, vector<int>(9));

bool endflag = false;

bool check(int x,int y, int value)
{
	for (int i = 0; i < 9; ++i)
	{
		if (map[i][y] == value)
		{
			return false;
		}

		if (map[x][i] == value)
		{
			return false;
		}
	}

	int lx = x / 3;
	int ly = y / 3;
	lx *= 3;
	ly *= 3;

	for (int i = lx; i < lx + 3; ++i)
	{
		for (int j = ly; j < ly + 3; ++j)
		{
			if (value == map[i][j]) return false;
		}
	}
	return true;
}


void simulate(const vector<pair<int,int>>& s, int depth)
{	
	if (endflag) return;
	if (s.size() == depth)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				cout << map[i][j] << " ";
			}
			cout << '\n';
		}

		endflag = true;
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		
		if (check(s[depth].first, s[depth].second,i) == true)
		{
			map[s[depth].first][s[depth].second] = i;
			simulate(s, depth + 1);
			map[s[depth].first][s[depth].second]= 0;
		}
	}


}



int main() {
	

	vector<pair<int, int>> zeros;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				zeros.push_back({ i,j });
			}
		}
	}
	

	simulate(zeros,0);
   
}