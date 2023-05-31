#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> lopi; // location, priority 순으로 들어가는 queue 생성
    pair<int, int> temp = make_pair(0,0); // pair 저장용 변수
    vector<int> ans; // 출력순서 저장하는 큐 (location만 저장)  
    int size = priorities.size();
    
    for (int i = 0; i < size; ++i){ // 큐에다가 location, priority값 넣어줌
        temp = make_pair(i, priorities[i]); // i는 기존의 location을 넣기 위해서 만들어준 변수
        lopi.push(temp);
    }
    
    while (!lopi.empty()){
        int max = 0;
        for (int i = 0; i < lopi.size(); ++i){ // max값 찾기
            if ((lopi.front()).second > max) // lopi[i]의 priority값이 더 크면
                max = (lopi.front()).second; // max값 새로고침
            temp = lopi.front();
            lopi.pop();
            lopi.push(temp);
        }
        
        for (int i = 0; i < lopi.size(); ++i){ // 출력해야 할 문서를 찾으면 큐에서 빼서 ans에 위치값 저장
            if((lopi.front()).second == max){
                temp = lopi.front();
                lopi.pop();
                ans.push_back(temp.first);
                break; // while문 다시 시작
            }
            else{
                temp = lopi.front();
                lopi.pop();
                lopi.push(temp);
            }
        }
    }
    
    for (int i = 0; i < ans.size(); ++i){
        if(ans[i] == location){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}