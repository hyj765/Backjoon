#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, long long> wtable;
    for(int i=0; i<weights.size(); ++i)
    {
        if(wtable.find(weights[i]) != wtable.end())
        {
            wtable[weights[i]]++;
        }else{
            wtable.insert({weights[i],1});
        }
    }
    
    for(int i=0; i<weights.size(); ++i)
    {
        long long value = weights[i]*2;
        if(value%3 ==0 && wtable.find(value/3) != wtable.end())
        {
            answer += wtable[value/3];
        }
        
        if(value%4 == 0 && wtable.find(value/4) != wtable.end())
        {
            answer += wtable[value/4];
        }
        
        value = weights[i]*3;
        if(value %4 ==0 && wtable.find(value/4)!= wtable.end())
        {
            answer += wtable[value/4];
        }
        
    }
    
    for(int i=100; i<=1000; ++i)
    {
        if(wtable[i] >= 2)
        {
            answer += (wtable[i] * (wtable[i]-1)) / 2;
        }
    }
    
    
    return answer;
}