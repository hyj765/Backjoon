#include <string>
#include <vector>
#include<numeric>
#include<deque>
#include<iostream>
using namespace std;
#define ll long long

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    ll sum1 = 0, sum2=0;
    sum1 = accumulate(queue1.begin(),queue1.end(),0);
    sum2 = accumulate(queue2.begin(),queue2.end(),0);
    deque<int> q1,q2;
    if((sum1 + sum2) %2 != 0 ) {
        //cout << "걸림" << endl;
        return -1;
    }
    for(int i=0; i<queue1.size(); ++i) q1.push_back(queue1[i]);
    for(int i=0; i<queue2.size(); ++i) q2.push_back(queue2[i]);
    bool flag = false;
    while(answer < queue1.size() * 4){
        
        if(sum1 > sum2){
            sum2 += q1.front();
            sum1 -= q1.front();
            q2.push_back(q1.front());
            q1.pop_front();
            answer++;
        }else if(sum2 > sum1){
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push_back(q2.front());
            q2.pop_front();
            answer++;
        }else{
            return answer;
        }
        
        
    }
    
    return -1;
}