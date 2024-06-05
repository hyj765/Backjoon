#include<iostream>
#include<algorithm>
using namespace std;

char chlist[] = "aeiou";

bool check1(const char target)
{

	for (int i = 0; i < 5; ++i)
	{
		if (target == chlist[i])
		{
			return true;
		}

	}

	return false;
}

bool getCheckList( const string& target)
{
	int cnt = 1;
	bool previous = false;
	char precharacter = ' ';
	bool gatherCheck = false;
	for (int i = 0; i < target.size(); ++i)
	{
		
		bool temp = check1(target[i]);
		if (temp)
		{
			gatherCheck = true;
		}

		if (previous == temp &&  i != 0)
		{
			cnt++;
			if (cnt == 3)
			{
				return false;
			}

		}
		else if(i != 0)
		{
			cnt = 1;
		}
		
		if (precharacter == target[i] && target[i] != 'e' && target[i] != 'o')
		{
			return false;
		}
		
		precharacter = target[i];
		previous = temp;
	}

	if (gatherCheck == false)
	{
		return false;
	}

	return true;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int bigaddress = -1;
	int same = 0;
	int vindo = 0;
	
	
	string n;
	while (1)
	{
		cin >> n;
		if (n == "end")
		{
			break;
		}
		if (getCheckList(n))
		{
			cout << '<' << n << '>' << " is acceptable." << endl;
		}
		else 
		{
			cout << '<' << n << '>' << " is not acceptable." << endl;
		}


	}

	
	
}