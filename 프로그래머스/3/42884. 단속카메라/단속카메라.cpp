#include <string>
#include <vector>
#include<algorithm>
using namespace std;

/*
   
   --- 
        ------- 
    ------
              ---
   
   
*/

bool compare(vector<int> a, vector<int> b){
   
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(),routes.end(),compare);
   int out = routes[0][1];
    for(vector<int> route:routes){
        if(route[0] > out){
            answer++;
            out = route[1];
        }
        
        if(route[1] <= out) out = route[1];
    }
    
    return answer;
}