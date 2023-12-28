#include <iostream>
#include <vector>
#include <algorithm>
#include<map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,query;
    cin >> n;
    map<int, int> hash;
    vector<int> ar(n);

    for (int i = 0; i < n; ++i) cin >> ar[i];
        
    sort(ar.begin(), ar.end());
    cin >> query;
    for (int i = 0; i < query; ++i) {
        int number;
        cin >> number;
        if (!hash[number]) {
            int value = upper_bound(ar.begin(), ar.end(), number) - lower_bound(ar.begin(), ar.end(), number);
            hash[number] = value;
            cout << value << " ";
        }
        else {
            cout << hash[number] << " ";
        }

    }



    return 0;
}
