#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int i=0;
    int cur =0;
    queue<pair<int,int>> trucks;
    while(i < truck_weights.size() || !trucks.empty()){
        answer++;
        if(!trucks.empty()){
            if(answer - trucks.front().second >= bridge_length){
                cur -= trucks.front().first;
                trucks.pop();
                //cout << answer << endl;
            }
        }
        if(cur + truck_weights[i] <= weight && trucks.size() < bridge_length  && i < truck_weights.size()){
           // cout << answer << endl;
            cur += truck_weights[i];
            trucks.push({truck_weights[i],answer});
            i++;
        }
    }
    
    
    return answer;
}