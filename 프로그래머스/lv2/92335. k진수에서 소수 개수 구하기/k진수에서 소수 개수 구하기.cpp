#include <string>
#include <vector>
#include<cmath>
#include<iostream>
using namespace std;
/*

 각 자리수에 0을 포함하지 않는 소수
 
*/

bool isPrime(long n){
    
    for(int i=2; i<= sqrt(n); ++i){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

string decimalToBase(long long number, int base) {
    if (number == 0) {
        return "0";
    }

    string result = "";
    while (number > 0) {
        int remainder = number % base;
        result = to_string(remainder) + result;
        number /= base;
    }

    return result;
}


int solution(int n, int k) {
    int answer = 0;
    
    
    string converted =decimalToBase(n,k);
    string temp = "";
    
    for(char ch:converted){
        if(ch != '0') temp.push_back(ch);
        else {
            if(temp.size() != 0){
                if(stol(temp) != 0 && stol(temp) != 1){
                    if(isPrime(stol(temp))){
                    answer++;
                    }
                }
                temp = "";
            }
        }
    }
    
    if(temp.size() != 0 && stol(temp) != 1){
        if(isPrime(stol(temp))){
            answer++;
        }
    }
    
    return answer;
}