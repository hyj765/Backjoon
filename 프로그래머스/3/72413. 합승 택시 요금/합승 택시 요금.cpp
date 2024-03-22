#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define inf 9999999
#define ll long long

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    ll answer = 0;
    vector<vector<unsigned int>> arr(n + 1, vector<unsigned int>(n + 1, inf));
    for (int i = 0; i <= n; i++) arr[i][i] = 0;
    for (int i = 0; i < fares.size(); ++i) {
        int src = static_cast<unsigned int>(fares[i][0]);
        int dst = static_cast<unsigned int>(fares[i][1]);
        int cost = static_cast<unsigned int>(fares[i][2]);

        arr[src][dst] = arr[dst][src] = cost;

    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (arr[i][k] == inf || arr[k][j] == inf) continue;
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }        
    }

    ll distance1 = arr[s][a] + arr[a][b];
    ll distance2 = arr[s][b] + arr[b][a];
    ll distance3 = arr[s][a] + arr[s][b];
    answer = min(min(distance1, distance2), distance3);
    
    for(int i=1; i<=n; ++i) {
        if(i == s || i == a || i == b) continue;
        answer = min(answer, (ll)(arr[s][i] + arr[i][a] + arr[i][b]));
    }

    return answer;
}

