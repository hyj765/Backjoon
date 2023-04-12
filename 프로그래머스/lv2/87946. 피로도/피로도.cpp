#include <string>
#include <vector>

using namespace std;

int maxVisitCnt = 0;
bool visit[8] = {false};
void simulate(int depth, const vector<vector<int>>& dungeons,int cur){
    maxVisitCnt = depth > maxVisitCnt ? depth : maxVisitCnt;
    for(int i=0; i<dungeons.size(); ++i){
        if(visit[i]) continue;
        if(cur < dungeons[i][0]) continue;
        visit[i] = true;
        simulate(depth+1,dungeons,cur-dungeons[i][1]);
        visit[i] = false;
    }
    
    
}




int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    simulate(0,dungeons,k);
    
    answer = maxVisitCnt;
    return answer;
}