#include <string>
#include <vector>

using namespace std;

int dp[100001];
constexpr int mod = 1000000007;

int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0] = 1;
    
    for(int i=0 ;i< money.size(); ++i)
    {
        for(int j= money[i]; j<= n; ++j)
        {
            dp[j] += dp[j - money[i]];
            dp[j] %= mod;
        }
    }
    
    answer = dp[n] % mod;
    return answer;
}