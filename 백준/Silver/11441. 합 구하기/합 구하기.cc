#include<iostream>
#include<vector>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    vector<int> arr(n+1,0);
   
    for (int i = 1; i < n+1; ++i) {
        int temp;
        cin >> temp;
        temp += arr[i - 1];
        arr[i] = temp;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        pair<int, int> cmd;
        cin >> cmd.first >> cmd.second;
        cout << arr[cmd.second] - arr[cmd.first - 1] << '\n';
    }


    return 0;

}