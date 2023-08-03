#include <string>
#include <vector>
#include<iostream>
#include<math.h>
using namespace std;

int dfs(int start,vector<vector<int>> node, vector<bool>& visit){
    int r = 1;
    visit[start] = true;
    //cout << start << " ";
    for(int s :node[start]){
        if(!visit[s]){
            r +=dfs(s,node,visit);
        }
    }
    
    return r;
}

int simulate(const vector<vector<int>> & wires,int m, int n){
    vector<vector<int>> node(n+1);
    vector<bool> visit(n+1,false);
    for(int i=0; i<wires.size(); ++i){
        if(i == m) continue;
        int snode = wires[i][0];
        int dnode = wires[i][1];
        node[snode].push_back(dnode);
        node[dnode].push_back(snode);
    }
    
    return dfs(1,node,visit);
}


int solution(int n, vector<vector<int>> wires) {
    
    int answer = n;
    for(int i=0; i<wires.size(); ++i){
        int s = simulate(wires,i,n);
       // cout << s << endl;
        int another = abs(n - s);
        answer = min(answer,abs(another - s));
    }
          
    return answer;
}