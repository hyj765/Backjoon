#include <string>
#include <vector>
#include<iostream>
#include <algorithm>
using namespace std;
//2명 씩 밖에 못나간다. , 무게도 한정되어있다.
// 1 예제 
/*
    50 50 70 80  100     
    20 30 70 80 90       3
*/


int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int cur = 0;
    while(people.size() > cur){
        int left = people.back();
        people.pop_back();
        if(people[cur] + left <= limit){
            answer++;
            cur++;
        }
        else answer++;
    }
    
 
    return answer;
}