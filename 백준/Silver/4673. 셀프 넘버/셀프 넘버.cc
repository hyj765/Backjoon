#include<iostream>

int IsSelf(int num)
{
	int number = num;

	while (num != 0)
	{
		number = number + (num % 10);
		num = num / 10;
	}

	return number;


}
bool check[10001];

int main()
{
	int n = 0;
	

	for (int i = 1; i < 10001; ++i)
	{
		n = IsSelf(i);

		if (n < 10001)
		{
			check[n] = true;
		}
	}
	
	for (int i = 1; i < 10001; ++i)
	{
		if (check[i] == false)
		{
			std::cout << i << std::endl;
		}
	}


}