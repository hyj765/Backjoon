#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
/*
    1. 철수가 가진 카드가 적힌 모든 숫자를 나눌 수 있으며 영희가 가진 카드를 무엇 하나도 나눌 수 없는 양의 정수
    2. 영희 ....
    
    가장 큰양의 정수 A = 최대 공약수

*/


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int len = arrayA.size();
    /*
     getgcd
    */
    bool fflag = false;
    int cur = arrayA[0];
    for(int i=0 ;i<arrayA.size(); ++i)
    {
        cur = gcd(cur, arrayA[i]);
        if(cur == 1) break;
    }
    
    if(cur != 1)
    {
        for(int i=0; i<arrayB.size(); ++i)
        {
            if(arrayB[i] % cur == 0) {
                fflag = true;
                break;
            }
        }
        if(fflag == false) {
            answer = cur;
        }
    }
    fflag = false;
    cur = arrayB[0];
    for(int i=0; i < arrayB.size(); ++i)
    {
        cur = gcd(cur,arrayB[i]);
        if(cur == 1) break;
    }
    
    if(cur != 1)
    {
        for(int i=0; i<arrayA.size(); ++i)
        {
            if(arrayA[i] % cur == 0) {
                fflag = true;
                break;
            }
        }
        
        if(fflag == false)
        {
            answer = max(cur,answer);
        }
    }
    
    return answer;
}