#include <string>
#include <vector>
#include <stack>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> subcontainer;
    queue<int> maincontainer; 
    // 1 2 3 4 5
    for(int i=0; i<order.size(); ++i){
        maincontainer.push(i+1);
    }
    
    for(int i=0; i<order.size(); ++i){
        if(!subcontainer.empty()){
            //cout << "sub " << subcontainer.top(); 
            if(subcontainer.top() == order[i]){
                subcontainer.pop();
                answer++;
                continue;
            }
        }
        if(!maincontainer.empty()){
            while(order[i] > maincontainer.front() && !maincontainer.empty()){
                subcontainer.push(maincontainer.front());
                //cout << maincontainer.front() << endl;
                maincontainer.pop();
            
            /*
                메인con -> subcon으로 보내는 건 가능하지만
                subcon -> maincon은 불가능.
                1000000기 때문에 n^2가 되는 순간 아웃.
                메인컨테이너가 비어있는 상태에서 subcon이 다르면 탈락.
                
                1. order[i]보다 낮으면 전부 sub로 보낸다.
                2. order[i]는 결국 한번 main에서 추출됨.
                3. 그 다음 order[i+1]이 subcon의 top 값인 지 확인 맞다면 subcon에서 추출
                4. 아닐 경우 maincontainer와 비교해서 넣을 수 있는 값인 경우 maincontainer에 넣고            ex)  order 4 , 6 이면 1~3까지 넣고 다시 sub에 5를 넣으면 main에서 추출가능
                5. 아닌 경우 끝
            
            */
                
            }
        }
        if(!maincontainer.empty()&&maincontainer.front() == order[i]) {
            answer++;
            maincontainer.pop();
        }else{
            break;
        }
        
        
    }
    
    return answer;
}