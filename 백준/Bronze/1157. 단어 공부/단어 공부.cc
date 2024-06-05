#include<iostream>
#include<algorithm>
using namespace std;


int arr[200];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int bigaddress = -1;
	int same = 0;
	int vindo = 0;
	string n;
	cin >> n;

	for (int i = 0; i < n.size(); ++i)
	{
		arr[tolower(n[i])]++;
	}
	
	for (int i = 0; i < 200; ++i)
	{
		if (arr[i] > vindo) {
			vindo = arr[i];
			bigaddress = i;
			same = 1;

		}
		else if (arr[i] == vindo)
		{
			same++;
		}
	}
	
	if (same == 1)
	{
		cout << static_cast<char>(toupper(bigaddress));
	}
	else if (same > 1)
	{
		cout << "?" << endl;
	}

	
}