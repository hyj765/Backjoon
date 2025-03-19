#include <string>
#include <vector>
#include<iostream>
using namespace std;

int server[24];

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    
    for(int i=0; i<players.size(); ++i)
    {
        int users = players[i] - ( server[i] * m );
        if(users < m)
        {
            continue;   
        }
        else
        {
            int needsServerCount = users / m;
            
            for(int j=0; j<k; ++j)
            {
                if( (i +j) > 24 ){ 
                   continue;
                }
                server[i + j] += needsServerCount;
            }
            answer += needsServerCount;
        }
    
    }
    
    
    
    return answer;
}