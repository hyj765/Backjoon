#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
    vector<int> arr(3);    
    cin >> arr[0] >> arr[1] >> arr[2];
    
    sort(arr.begin(),arr.end());
    printf("%d",arr[1]);
    
}