#include <iostream>
#include <vector>
using namespace std;

int dp[100000][4];


int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i=1; i<land.size(); ++i){
        land[i][0] += max(land[i-1][3],max(land[i-1][1],land[i-1][2]));
        land[i][1] += max(land[i-1][3],max(land[i-1][0],land[i-1][2]));
        land[i][2] += max(land[i-1][3],max(land[i-1][0],land[i-1][1]));
        land[i][3] += max(land[i-1][1],max(land[i-1][0],land[i-1][2]));
    }
    int len = land.size() -1 ;
    answer = max(land[len][3],max(max(land[len][0],land[len][1]),land[len][2]));
    return answer;
}