#include<iostream>
using namespace std;




int main()
{
	int a;
	cin >> a;
	for (int i = 1; i <= 9; ++i)
	{
		printf("%d * %d = %d\n",a,i, a*i );
	}
}