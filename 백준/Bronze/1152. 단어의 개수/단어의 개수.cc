#include<iostream>
#include<sstream>
using namespace std;



int main()
{

    string str;
    getline(cin, str);
    if (str.length() == 1 && str[0] == ' ')
    {
        cout << 0;
        return 0;
    }
    int answer = 1;
    for (int i = 1; i < str.length() -1; ++i)
    {
        if (str[i] == ' ') answer++;
    }

    cout << answer;
}