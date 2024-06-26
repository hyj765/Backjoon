#include<iostream>
#include<vector>
using namespace std;


int main()
{

	int start, end;

	cin >> end >> start;
	int previous;
	int cnt = 1;
	bool bad = false;
	while (end != start)
	{
		previous = start;

		if (start % 2 == 0)
		{
			start /= 2;
			cnt++;
		}
		else if(start % 10 == 1){
			start -= 1;
			start /= 10;
			cnt++;
		}

		//cout << start << endl;

		if (previous == start)
		{
			bad = true;
			break;
		}
	}

	if (bad)
	{
		cout << "-1";
	}
	else {
		cout << cnt;
	}


}