#include <string>
#include<map>
#include<iostream>
using namespace std;

bool visit[11][11][4];

int solution(string dirs) {
    int x = 0;
    int y = 0;
    int answer = 0;
    //map<string,bool> visit;
    for(int i=0; i<dirs.size(); ++i){ 
        int dir;
        int nx,ny;
        switch(dirs[i]){
            case 'U' :{
                ny = y + 1;
                nx = x;
                if(ny > 5) continue;
                
                dir = 0;
                break;
            }
            case 'D' :{
                nx = x;
                ny = y -1;
                if(ny < -5) continue;
                
                dir = 2;
                break;
            }
            case 'R' :{
                nx = x + 1;
                ny = y;
                if(nx > 5) continue;
                
                dir = 1;
                break;
            }
            case 'L' :{
                nx = x - 1;
                ny = y;
                if(nx < -5) continue;
                dir = 3;
                break;
            }
        }
        
        if(!visit[x+5][y+5][dir] && !visit[nx+5][ny+5][(dir+2)%4]){
            cout << "first " << x << " "<< y << dirs[i] << endl;
            cout << "first " << nx << " " << ny << dirs[i] << endl;
            visit[x+5][y+5][dir] = true;
            visit[nx+5][ny+5][(dir+2)%4] = true;
            answer++;
        }else{
            cout << "second " << x << " " << y << dirs[i] << endl;
        }
        x = nx;
        y = ny;
    }
    
    return answer;
}