#include<iostream>
#include<vector>
using namespace std;

int dp[16];
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ar(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].first >> ar[i].second;
    }

    for (int i = 0; i < n; i++) {
        if (i + ar[i].first > n) continue;
        if (dp[i + ar[i].first] < dp[i] + ar[i].second) {
            dp[i + ar[i].first] = dp[i] + ar[i].second;
            for (int j = i + ar[i].first; j <= n; j++) {
                if (dp[j] < dp[i + ar[i].first]) dp[j] = dp[i + ar[i].first];
            }
        }
    }
    cout << dp[n];

}