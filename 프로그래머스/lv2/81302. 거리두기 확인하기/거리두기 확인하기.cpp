#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int getDistance(pair<int,int> a1, pair<int,int> a2){
    return abs(a1.first - a2.first) + abs(a1.second - a2.second);
}

bool bfs(pair<int,int> start, pair<int,int> end, vector<vector<char>> map){
    queue<vector<int>> s;
    s.push({start.first,start.second,0});
    while(!s.empty()){
        int cx = s.front()[0];
        int cy = s.front()[1];
        int cnt = s.front()[2];
        s.pop();
        if(cx == end.first && cy == end.second) {
            return true;
        }
        if(cnt == 2) continue;
        for(int i=0; i<4; ++i){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(map[nx][ny] == 'X') continue;
            map[nx][ny] == 'X';
            s.push({nx,ny,cnt+1});
        }
    }
    
    return false;
} 


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5,1);
    vector<vector<vector<char>>> maplist(5,vector<vector<char>>(5,vector<char>(5)));
    vector<vector<pair<int,int>>> players(5);
    for(int i = 0; i<places.size(); ++i){
        for(int j=0; j<places[i].size(); ++j){
            for(int k=0; k<places[i][j].size(); ++k){
                maplist[i][j][k] = places[i][j][k];
                if(maplist[i][j][k] == 'P'){
                    players[i].push_back({j,k});
                }
            }
        }
    }
    
    for(int i=0; i<5; ++i){
        for(int j=0; j<players[i].size(); ++j){
            for(int k=j; k<players[i].size(); ++k){
                if(j == k) continue;
                if(getDistance(players[i][j],players[i][k]) <= 2){
                    
                    if(bfs(players[i][j],players[i][k],maplist[i])){
                       answer[i] =0; 
                    }
                    
                }   
            }
        }
        cout << '\n';
    }
    
    return answer;
}