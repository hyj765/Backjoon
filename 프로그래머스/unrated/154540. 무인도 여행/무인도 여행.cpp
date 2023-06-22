#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,m;
int dfs(int x,int y, const vector<string>& maps, vector<vector<bool>>& visit){
    int s = maps[x][y] - '0';
    visit[x][y] = true;
    for(int i=0; i<4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(maps[nx][ny] == 'X') continue;
        if(visit[nx][ny]) continue;
        s+= dfs(nx,ny,maps,visit);
    }
    
    return s;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visit(maps.size(),vector<bool>(maps[0].size()));
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(maps[i][j] == 'X') continue;
            if(visit[i][j]) continue;
            answer.push_back(dfs(i,j,maps,visit));
        }
    }
    if(answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}