#include <iostream>

bool arr[1000001];
int main()
{
	int m, n;
	std::cin >> m >> n;

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i * i <= n; ++i) 
	{
		if (arr[i]) continue; 
		else
		{
			for (int j = 2; j * i <= n; ++j) 
			{
				arr[i * j] = true;
			}
		}
	}

	for (int i = m; i <= n; ++i) 
	{
		if (!arr[i]) std::cout << i << '\n';
	}
}