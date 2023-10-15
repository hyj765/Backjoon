#include <string>
#include <vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;


/*

*/

struct compare{
    
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(),jobs.end());
    int totaltime =0;
    int curtime=0;
    int tasks  =0;
    priority_queue<vector<int>,vector<vector<int>>,compare> qt;
  
    while(tasks < jobs.size() || !qt.empty()){
        
        if( tasks < jobs.size() && jobs[tasks][0] <= curtime){
            qt.push(jobs[tasks++]);
            continue;
        }
        
        if(!qt.empty()){
            curtime += qt.top()[1];
            totaltime += curtime - qt.top()[0];
            qt.pop();
        }
        else{
            curtime = jobs[tasks][0];
        }
    }
    
    answer = totaltime / jobs.size();
    
    return answer;
}