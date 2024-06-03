#include<iostream>
using namespace std;


bool arr[21];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string cmd;
		int number;
		cin >> cmd;


		if (cmd == "add")
		{
			cin >> number;
			arr[number] = true;
		}
		else if (cmd == "check")
		{
			cin >> number;
			cout << arr[number] << "\n";
		}
		else if (cmd == "remove")
		{
			cin >> number;
			arr[number] = false;
		}
		else if (cmd == "toggle")
		{
			cin >> number;
			arr[number] = -(arr[number] - 1);
		}
		else if (cmd == "all")
		{
			for (int j = 1; j <= 20; ++j)
			{
				arr[j] = true;
			}
		}
		else if (cmd == "empty")
		{
			for (int j = 1; j <= 20; ++j)
			{
				arr[j] = false;
			}
		}

	}


}