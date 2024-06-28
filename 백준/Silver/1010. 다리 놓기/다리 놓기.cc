#include<iostream>
using namespace std;

int main()
{
   int T;
    cin >> T;
    for(int i=0; i<T; ++i)
    {
        long long answer = 1;
        int n =0;
        int m = 0;
        int r = 1;
        cin >> n >> m;
        for(int j=m; j > m-n; --j)
        {
            answer = answer * j;
            answer = answer / r;
            r++;
        }
        cout << answer << '\n';
    }
    
}