#include<iostream>
#include<vector>
using namespace std;

int dp[1001];

int main()
{
    int sum =0;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) cin >> arr[i];
    dp[0] = 1;
    for(int i=0; i<n; ++i)
    {
        dp[i] = 1;
        for(int j=0; j<i; ++j)
        {
            if(arr[i] < arr[j])
            {
                dp[i] = max(dp[i],dp[j]+1);        
            }
        }
        sum = max(sum,dp[i]);
    }
    cout << sum;
    
}