#include<iostream>
using namespace std; 

int check(int a, int b , int c)
{
	if (a == 0 && b == 0 && c == 0)
	{
		return -1;
	}

	int cnt = 0;

	if (a > b && a > c)
	{
		if (a >= (b + c))
		{
			return 4;
		}
	}

	if (b > a && b > c)
	{
		if (b >= (a + c))
		{
			return 4;
		}
	}

	if (c > b && c > a)
	{
		if (c >= (b + a))
		{
			return 4;
		}
	}


	if (a == b) cnt++;
	if (a == c) cnt++;
	if (b == c) cnt++;

	if (cnt == 3)
	{
		return 1;
	}
	else if (cnt == 1)
	{
		return 2;
	}
	else
	{
		return 3;
	}

}




int main()
{
	int a, b, c;

	while (true)
	{
		cin >> a >> b >> c;

		int status = check(a, b, c);
		if (status == -1)
		{
			break;
		}
		else if (status == 1)
		{
			cout << "Equilateral" << endl;
		}
		else if (status == 2)
		{
			cout << "Isosceles" << endl;
		}
		else if (status == 3)
		{
			cout << "Scalene" << endl;
		}
		else 
		{
			cout << "Invalid" << endl;
		}

		
	}




}