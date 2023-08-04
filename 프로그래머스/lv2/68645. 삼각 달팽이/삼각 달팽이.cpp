#include <string>
#include <vector>
#include<iostream>
using namespace std;

int dx[] = {1,0,-1};
int dy[] = {0,1,-1};
vector<int> solution(int n) {
    vector<int> answer;
    
    vector<vector<int>> map(n,vector<int>(n,0));
    int idx = 1;
    int curX = 0;
    int curY = 0;
    map[0][0] = 1;
    int i =0;
    while(1){
        curX += dx[i%3];
        curY += dy[i%3];
        if(curX == n || curY == n || map[curX][curY] != 0){
            curX -= dx[i%3];
            curY -= dy[i%3];
            i++;
            curX += dx[i%3];
            curY += dy[i%3];
            if(curX == n || curY == n || map[curX][curY] != 0) break; 
        }
        
        map[curX][curY] = ++idx;
    }
    
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(map[i][j] == 0) continue;
            answer.push_back(map[i][j]);
        }
    }
    
    
    
    return answer;
}