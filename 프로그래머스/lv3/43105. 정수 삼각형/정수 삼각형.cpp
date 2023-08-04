#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int dp[500][500];
    dp[0][0] = triangle[0][0];
    dp[1][0] = triangle[1][0] + dp[0][0];
    dp[1][1] = triangle[1][1] + dp[0][0];
    int siz = triangle.size();
    for(int i=2; i<siz; ++i){
        for(int j=0; j<=i; ++j){
            
            if(j==0) dp[i][j] = triangle[i][j] + dp[i-1][j];
            else if(j == i) dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            else dp[i][j] = triangle[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
            
        }   
    }
    
    for(int i=0; i<triangle[siz-1].size(); ++i){
        answer = max(dp[siz-1][i],answer);
    }
    
    return answer;
}