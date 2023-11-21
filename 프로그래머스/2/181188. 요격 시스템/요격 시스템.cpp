#include <string>
#include<iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

bool compare(vector<int> a , vector<int> b){
    
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(),targets.end(),compare);    
    int temp;
    temp = targets[0][1];
   
    if(targets.size() == 1) return 1;
    for(int i=1; i<targets.size(); ++i){
        if(temp <= targets[i][0]){
            temp = targets[i][1]; 
            answer++;
        }else{
            temp = min(targets[i][1],temp);
        }
        // cout << temp << " " << targets[i][0] << " " << targets[i][1] << endl;
    
        
    
    }
    
    return answer;
}