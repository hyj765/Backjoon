#include<iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
   
    string answer = "";
    int remainder = 0;
    while(n != 0)
    {
        remainder = n % 3; // 13                    1
        n /= 3; //      4
        if(remainder == 0)
        {
            answer = "4" + answer;
            --n;
        }
        else
            answer = to_string(remainder) + answer;
    }

    
    return answer;   
}