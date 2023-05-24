#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> vis(maps.size(), vector<int>(maps[0].size(),100000));
    vis[0][0] = 1;
    queue<vector<int>> que;
    que.push({0,0,1});
    while(!que.empty()){
        int x = que.front()[0];
        int y = que.front()[1];
        int t = que.front()[2];
        que.pop();
       // printf("%d %d %d\n", x,y,t);
        if(x == n-1 && y == m-1){
            return t;
        }
        
        for(int i=0; i<4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(maps[nx][ny] == 0) continue;
            if(vis[nx][ny] <= t+1) continue;
            vis[nx][ny] = t+1;
            que.push({nx,ny,t+1});
        }
        
    }
    
    return answer;
}