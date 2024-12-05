#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;


int lcd(int a, int b)
{
    return (a*b) / std::gcd(a,b);
}


int solution(int n) {
    int answer = 0;
    
    answer = lcd(6,n)/6;
    
    
    return answer;
}