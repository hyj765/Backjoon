#include<iostream>
#include<vector>
using namespace std;


int isPalindrome(int lidx, int ridx,const string& str, bool ischeck)
{
	while (lidx < ridx)
	{
		if (str[lidx] != str[ridx])
		{
			if (ischeck == false) {

				int one = isPalindrome(lidx + 1, ridx, str, true);
				int two = isPalindrome(lidx, ridx - 1, str, true);
				if (one == 0 || two == 0)
				{
					return 1;
				}
			}
			return 2;
		}

		lidx++;
		ridx--;
	}

	return 0;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		
		cout << isPalindrome(0, str.size() - 1, str, false) << endl;
	}
	
}