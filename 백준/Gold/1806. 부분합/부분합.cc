#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int answer = INT32_MAX;
    int n, s;
    int start = 0, end = 0;
    cin >> n >> s;
    int sum = 0;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    while (start <= end) {
        if (sum >= s) {	
            answer = min(answer, end - start);	
            sum -= arr[start++];
        }
        else if (end == n) break;
        else sum += arr[end++];
    }
    


    if (answer == INT32_MAX)
    {
        answer = 0;
    }

    cout << answer;

}