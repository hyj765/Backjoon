#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

vector<int> arr;

int find(int a){
    if(arr[a] == a) return a;
    
    return arr[a] = find(arr[a]); 
}

void unionn(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b){
        arr[b] = a;
    }
}

void init(int n){
    for(int i=0; i<n; ++i){
        arr.push_back(i);
    }
}

bool compare(vector<int> a1, vector<int> a2){
    return a1[2] < a2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    init(n);
    sort(costs.begin(),costs.end(),compare);
    
    for(int i=0; i<costs.size(); ++i){
        int src = costs[i][0];
        int dst = costs[i][1];
        int cost = costs[i][2];
        
        if(find(src) != find(dst)){
            unionn(src,dst);
            answer += cost;
        }
    }
    cout << answer << endl;
    
    
    return answer;
}