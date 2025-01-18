#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

pair<int,int> start;
pair<int,int> goal;

int answer = 999999999;

vector<vector<bool>> visit(100, vector<bool>(100,0));


int dx[] = {1,0,0,-1};
int dy[] = {0,-1,1,0};

pair<int,int> move(pair<int,int> cur,int dir, const vector<string>& map)
{
    int ex = map.size();
    int ey = map[0].size();
    
    while(true)
    {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if(nx >= ex || nx < 0 || ny >=  ey || ny < 0)
        {
            break;
        }
        if(map[nx][ny] == 'D')
        {
            break;
        }
        
        cur.first = nx;
        cur.second = ny;
    }
    
    return cur;
}


void simulate(pair<int,int> location, const vector<string>& map)
{
    queue<vector<int>> q;
    q.push({location.first,location.second,0});
    while(q.empty() == false)
    {
        int cx = q.front()[0];
        int cy = q.front()[1];
        int depth = q.front()[2];
        q.pop();
        if(cx == goal.first && cy == goal.second)
        {
            answer = depth;
            break;
        }
        
        visit[cx][cy] = true;        
        for(int i=0; i<4; ++i)
        {
            auto next = move({cx,cy},i,map);
            if(visit[next.first][next.second] == false)
            {
                q.push({next.first,next.second,depth+1});
            }
        }
        
    }
    
}

int solution(vector<string> board) {
    
    for(int i=0; i<board.size(); ++i)
    {
        for(int j=0; j<board[i].size(); ++j)
        {
            if(board[i][j] == 'R')
            {
                start = {i,j};
            }
            else if(board[i][j] == 'G')
            {
                goal = {i,j};
            }
        }
            
    }
    
    simulate(start,board);
    if(answer == 999999999)
    {
        answer = -1;
    }
    
    return answer;
}