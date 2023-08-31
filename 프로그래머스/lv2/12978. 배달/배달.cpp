#include <iostream>
#include <vector>
#include<queue>
using namespace std;


int solv(vector<vector<pair<int,int>>>& table,int n, int limit){
    vector<bool> visit(n+1,false);
    vector<int> dist(n+1,99999999);
    priority_queue<pair<int,int>> qt;
    qt.push({0,1});
    dist[1] = 0;
    while(!qt.empty()){
        int cur = qt.top().second;
        int w = -qt.top().first;
        
        visit[cur] = true;
        qt.pop();
        
        for(pair<int,int> v:table[cur]){
            int next = v.second;
            int nw = v.first;
            
            if(!visit[next] && dist[next] > nw + w){
                dist[next] = nw + w;
                qt.push({-dist[next],next});
            }
        }
        
        
        
    }
    int r = 0;
    for(int i=1; i<n+1; ++i){
        if(limit >= dist[i]) r++;
    }
    
    return r;
}



int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> nodes(N+1);
    for(vector<int> r:road){
        int start = r[0];
        int end = r[1];
        int w = r[2];
        nodes[start].push_back({w,end});
        nodes[end].push_back({w,start});
    }
    
    answer=solv(nodes,N,K);
    
    
    return answer;
}