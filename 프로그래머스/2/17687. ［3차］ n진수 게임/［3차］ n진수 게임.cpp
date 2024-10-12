#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const char digits[] = "0123456789ABCDEF";

std::string decimalToBase(int decimal, int base) {
    if (decimal == 0) return "0";
    std::string result = "";

    while (decimal > 0) {
        result += digits[decimal % base];
        decimal /= base;
    }

    std::reverse(result.begin(), result.end());
    return result;
}



string solution(int n, int t, int m, int p) {
    string answer = "";
    int tt = 0;
    int turn = 0;
    int cur = 0;
    while (true) {
        if(tt == t) break;
        string temp = decimalToBase(cur, n);
        for (int j = 0; j < temp.size(); ++j)
        {
            
            if (turn % m == p - 1)
            {
                if(tt == t) break;
                answer += temp[j];
                tt++;
            }
            turn++;
        }
        cur++;
    }
    return answer;
}
