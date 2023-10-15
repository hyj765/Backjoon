#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;


bool flag[100][100][2];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int mv = INT32_MAX;

struct compare{
    
  bool operator()(vector<int> a, vector<int> b){
      return a[2] > b[2];
  }  
    
};

void simulate(vector<string> maps,pair<int,int> start,pair<int,int> end,int n , int m){
    
    priority_queue<vector<int>,vector<vector<int>>,compare> q;
    q.push({start.first,start.second,0,0});
    int cnt = 0;
    while(!q.empty()){
        
        int cx = q.top()[0];
        int cy = q.top()[1];
        int cur = q.top()[2];
        int b = q.top()[3];
        q.pop();
        
        //cout << cx << " " << cy << " " << cur << endl;
        if(b != cnt) continue;
        if(cnt == 1 && cx == end.first && cy == end.second && mv > cur){
                mv = cur;
                return;
         }
        
        for(int i=0; i<4; ++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if(maps[nx][ny] == 'X') continue;
            if(flag[nx][ny][b]) continue;
            if(maps[nx][ny] == 'L'){
                cnt +=1;
                flag[nx][ny][cnt] = true;
                q.push({nx,ny,cur+1,cnt});
            }else{
                flag[nx][ny][b] = true;
                q.push({nx,ny,cur+1,b});
            }
        }
        
    }
    
}


int solution(vector<string> maps) {
    int answer = -1;
    
    
    pair<int,int> start;
    pair<int,int> end;
    
  
    for(int i=0; i<maps.size(); ++i){
        for(int j=0; j<maps[i].size(); ++j){
            if(maps[i][j] == 'S') start = {i,j};
            else if(maps[i][j] == 'E') end = {i,j};
        }
    }
    
    simulate(maps,start,end,maps.size(),maps[0].size());
    
    if(mv == INT32_MAX) answer = -1;
    else answer = mv;
    
    
    return answer;
}