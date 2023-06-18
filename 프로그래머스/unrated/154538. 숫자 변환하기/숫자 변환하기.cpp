#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    
    queue<pair<int,int>> q;
    q.push({y,0});
    if(x == y) return 0;
    while(!q.empty()){
        int cur = q.front().first;
        int turn = q.front().second;
       // cout << cur << " " << turn << endl;
        q.pop();
        if(cur == x){
            answer = turn;
            break;
        }
        if(cur /2 >= x && cur % 2 == 0) q.push({cur/2,turn+1});
        if(cur /3 >= x && cur %3 == 0) q.push({cur/3,turn+1});
        if(cur - n >= x) q.push({cur-n,turn+1});
    }
    if(answer == 0) answer = -1;
    
    return answer;
}