#include<iostream>
using namespace std;




int main()
{
    int a, b;
    cin >> a >> b;

    printf("%d\n", a + b);
    printf("%d\n", a - b);
    printf("%d\n", a * b);
    printf("%d\n", (a / b));
    int s = a % b;
    printf("%d\n", s);
}