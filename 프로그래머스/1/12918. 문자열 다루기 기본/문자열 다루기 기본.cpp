#include <string>
#include <vector>
#include<iostream>
using namespace std;

bool isNum(char c){
    if(c >= 48 && c <= 57 ){
        cout <<"상자 부수기";
        return true;
    }
    return false;
}

bool solution(string s) {
    bool answer = true;
    bool cnt = false;
    if(s.size() == 4 || s.size() == 6){
        cnt = true;
        for(int i=0; i<s.size(); ++i){
            if(!isNum(s[i])){
                cnt= false;
                break;
            }
        }    
    }
    answer = cnt;
    return answer;
}