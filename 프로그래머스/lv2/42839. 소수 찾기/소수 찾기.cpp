#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>
using namespace std;
/*

 17 71 71

*/
set<int,greater<int>> values;
bool numbercheck[7];
void getvalues(string cur, const string& numbers){
    if(cur.size() >= 1) {
        values.insert(stoi(cur.c_str()));
    }
    for(int i=0; i<numbers.size(); ++i){
        if(numbercheck[i]) continue;
        numbercheck[i] = true;
        getvalues(cur+numbers[i],numbers);
        numbercheck[i] = false;
        
    }
    
}

bool isPrime(int s){
    if(s < 2) return false;
    int end = sqrt(s);
    for(int i=2; i<= end; ++i){
        if(s %i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    getvalues("",numbers);
    //int m = values[0];
    
    for(int v:values){
        if(isPrime(v)) answer++;
    }
    
    
    return answer;
}