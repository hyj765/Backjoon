#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;
// 2 3 5
// 
vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> s;
    for(int i= numbers.size()-1; i>=0; i--){
        while(1){
            if(s.empty()){
                answer[i] = -1;
                break;
            }else if(s.top() > numbers[i] ){
                answer[i] = s.top();
                break;
            }
            s.pop();  
        }
        s.push(numbers[i]);
    }
    
    return answer;
}