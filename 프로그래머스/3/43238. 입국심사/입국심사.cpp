#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    ll min = 1;
    ll max = (n/times.size())* times.back();
    
    while(min <= max){
        ll middle = (max + min)/2;
        ll proceed = 0;
        for(int i=0; i<times.size(); ++i){
            proceed += (middle / (ll)times[i]);
        }
        if(proceed >= n){
            max = middle - 1;
            answer = middle;
        }else{
            min = middle+1;
        }
        
    }
    
    
    return answer;
}