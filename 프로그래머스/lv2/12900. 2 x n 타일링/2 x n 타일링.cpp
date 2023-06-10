#include <string>
#include <vector>

using namespace std;

//n = 1  dp =1
/*
 n=2 dp=2
 n=3 dp=3
 n=4 dp=5
 n=5 dp= 8
*/
int dp[60001];
int solution(int n) {
    int answer = 0;
    dp[0]= 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; ++i){
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    }
    
    answer = dp[n];
    return answer;
}