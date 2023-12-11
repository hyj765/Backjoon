#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll FindMax(const vector<ll> &ar){
   
    vector<ll> dp(ar.size());
    
    dp[0] = ar[0];
    ll value = INT32_MIN;
    for(int i=1; i<ar.size(); ++i){
        dp[i] = max(dp[i-1] +(ll)ar[i], (ll)ar[i]);
        value = max(dp[i],value);
    }
    return value;
}


long long solution(vector<int> sequence) {
    long long answer = INT32_MIN;
    
    vector<ll> ar1,ar2;
    int temp1 = 1;
    int temp2 = -1;
    for(int i=0; i<sequence.size(); ++i){
        ar1.push_back(sequence[i]*temp1);
        ar2.push_back(sequence[i]*temp2);
        
        answer = max(answer, ar1[i]);
        answer = max(answer, ar2[i]);
        temp1 *= -1;
        temp2 *= -1;
        
    }
    answer = max(FindMax(ar1),answer);
    answer = max(FindMax(ar2),answer);
    
    
    
    return answer;
}