#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(const vector<vector<int>>& v, int x,int y){
    int cnt = 0;
    for(int i=0; i<v.size(); ++i){
        if(v[i][0] <= x && v[i][1] <= y){
            cnt++;
            continue;
        } 
        if(v[i][1] <= x && v[i][0] <= y){
            cnt++;
            continue;
        }
        break;
    }
    if(cnt == v.size()) return true;
    
    return false;
    
    
}



int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max1 = 0;
    int max2 = 0;
    for(int i=0; i<sizes.size(); ++i){
    
        if(sizes[i][0] > sizes[i][1]){
            max1 = max(max1,sizes[i][0]);
            max2 = max(max2,sizes[i][1]);
        }else{
            max1 = max(max1,sizes[i][1]);
            max2 = max(max2,sizes[i][0]);
        }
        
    }
    answer = max1*max2;
    
    return answer;
}