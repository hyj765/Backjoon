#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long dp[100000];
long long solution(int n) {
    dp[0] = 0;
    dp[1] = 1;
    long long answer = 0;
    for (int i = 2; i <= 100000; ++i) {
        dp[i] = (dp[i - 2] + dp[i - 1] ) %1234567;
    }
    answer = (dp[n]);
    return answer;
}