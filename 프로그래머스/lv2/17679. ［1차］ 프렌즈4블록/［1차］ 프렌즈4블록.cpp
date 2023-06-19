#include <string>
#include <vector>
#include<set>
using namespace std;

int dx[] = {0,1,0};
int dy[] = {1,0,-1};

void drop(vector<string>& board,int n ,int m){
    
    for(int i=n-1; i>=0; --i){
        for(int j=m-1; j>=0; --j){
           int x = i;
            while(1){
               int nx = x+1;
               if(nx >= n) break;
               if(board[nx][j] != '0') break;
               board[nx][j] = board[x][j];
               board[x][j] = '0';
               x = nx;
           }  
        }
    }
    
}

bool check(int x, int y, const vector<string>& board,int n,int m){
    int value = board[x][y];
    for(int i=0; i<3; ++i){
        x += dx[i];
        y += dy[i];
        
        if(y < 0 || y >= m || x >= n) return false;
        if(board[x][y] != value) return false;
    }
    
    return true;
}

int solution(int n, int m, vector<string> board) {
    int answer = 0;
    
    /*
        while(1){
        체크 로직 -> 삭제할 블럭 list로 반환
        list 블럭 0으로 리셋
        if(list.size() == 0) break;
        블럭 내리기
        }
    */
    while(1){
        set<pair<int,int>> dellist;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(board[i][j] == '0') continue;
                if(check(i,j,board,n,m)){
                    int x = i;
                    int y = j;
                    dellist.insert({i,j});
                    for(int k=0; k<3; ++k){
                        x += dx[k];
                        y += dy[k];
                        dellist.insert({x,y});
                    }
                }
            }
        }        
        if(dellist.size() == 0) break;
        answer += dellist.size();
        for(pair<int,int> point:dellist){
            board[point.first][point.second] = '0';
        }    
        drop(board,n,m);
    }
    
    return answer;
}